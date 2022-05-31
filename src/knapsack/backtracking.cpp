#include "assignment/knapsack/backtracking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"

namespace assignment {

  std::vector<int> KnapsackBacktracking::solve(const Profits& profits, const Weights& weights, int capacity) const {
    assert(profits.size() == weights.size() && capacity > 0);

    int best_profit = 0;
    int best_profit_mask = 0;

    solve(profits, weights, capacity, -1, 0, 0, 0, best_profit, best_profit_mask);

    return mask2indices(profits, best_profit_mask);
  }

  void KnapsackBacktracking::solve(const Profits& profits, const Weights& weights, int capacity, int index, int mask,
                                   int weight, int profit, int& best_profit, int& best_profit_mask) const {

    if (index == static_cast<int>(profits.size())) {return;}

    if (weight > capacity) {return;}

    if (profit > best_profit) {
      best_profit = profit;
      best_profit_mask = mask;



    }

    index += 1;

    solve(profits, weights, capacity, index, set_bit(mask, index), weight+weights[index], profit+profits[index], best_profit, best_profit_mask);
    solve(profits, weights, capacity, index, mask, weight, profit, best_profit, best_profit_mask);
  }

}  // namespace assignment