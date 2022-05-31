#include "assignment/subsets/backtracking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"

namespace assignment {

  std::vector<std::vector<int>> SubsetsBacktracking::generate(const std::vector<int>& set) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());
    const int num_subsets = 1 << num_elems;

    auto subsets = std::vector<std::vector<int>>();
    subsets.reserve(num_subsets);

    generate(set, -1, 0, subsets);

    return subsets;
  }

  void SubsetsBacktracking::generate(const std::vector<int>& set, int index, int mask,
                                     std::vector<std::vector<int>>& subsets) const {
    assert(mask >= 0 && index >= -1);

    if (index == static_cast<int>(set.size()) - 1) {

      subsets.push_back(mask2indices(set,mask));

      return;
    }

    index += 1;


    generate(set,index,mask,subsets);

    generate(set,index, set_bit(mask,index),subsets);
  }

}  // namespace assignment