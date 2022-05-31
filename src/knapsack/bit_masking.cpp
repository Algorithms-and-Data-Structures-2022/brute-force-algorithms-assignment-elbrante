#include "assignment/knapsack/bit_masking.hpp"

#include <cassert>  // assert
#include <numeric>  // accumulate

#include "assignment/bits.hpp"

namespace assignment {

  static int sum_helper(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 0);
  }

  std::vector<int> KnapsackBitMasking::solve(const Profits& profits, const Weights& weights, int capacity) const {
    assert(profits.size() == weights.size() && capacity > 0);

    const auto num_elems = static_cast<int>(profits.size());
    const int num_subsets = 1 << num_elems;

    int best_profit = 0;
    int best_profit_mask = 0;

    if(capacity == sum_helper(weights)){
      return mask2indices(profits,num_subsets - 1);
    }
    for (int mask = 0; mask < num_subsets; mask++) {  // 2^N

      const auto masked_weights = mask2elems(weights, mask);

      const int curr_weight = sum_helper(masked_weights);

      // ... обработка случая превышения емкости рюкзака
      if(curr_weight > capacity) {
        continue;
      }

      // массив из "пользы" рассматриваемых элементов
      const auto masked_profits = mask2elems(profits, mask);

      // вычисление общей "пользы" рассматриваемых элементов
      const int curr_profit = sum_helper(masked_profits);

      if (curr_profit > best_profit) {
        best_profit = curr_profit;
        best_profit_mask = mask;
      }
    }




    return mask2indices(profits, best_profit_mask);
  }

}  // namespace assignment