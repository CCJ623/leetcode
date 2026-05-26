#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }

    auto min_prices = prices.front();
    int result = 0;
    for (const auto &price : prices) {
      min_prices = min(min_prices, price);
      result = max(result, price - min_prices);
    }

    return result;
  }
};