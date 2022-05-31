#include "assignment/subsets/bit_masking.hpp"

#include <cassert>

#include "assignment/bits.hpp"

namespace assignment {

  std::vector<std::vector<int>> SubsetsBitMasking::generate(const std::vector<int>& set) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    auto subsets = std::vector<std::vector<int>>(num_subsets);

    for(int mask = 0; mask < num_subsets; mask++) {
      std::vector<int> curr_subset;
      for (int position = 0; position < num_elems; position++) {
        if (is_bit_set(mask, position)) {
          subsets[mask].push_back(position);
        }

      }
    }
    return subsets;
  }

}  // namespace assignment