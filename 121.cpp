#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int result = 0;
    auto min_price = prices.front();
    for (size_t i = 1; i < prices.size(); ++i) {
      if (prices[i] >= min_price) {
        result = max(result, prices[i] - min_price);
      } else {
        min_price = min(min_price, prices[i]);
      }
    }

    return result;
  }
};