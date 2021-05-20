#include "../../test.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array of stock prices per day, return
 * the maximum profit that can be made from buying
 * and selling once.
 */
int findMaxProfit(vector<int>& prices) {
  if (prices.empty()) {
    return 0;
  }

  int max_profit = 0;
  int min_price = prices[0];
  for (auto price: prices) {
    int profit = price - min_price;
    max_profit = max(max_profit, profit);
    min_price = min(min_price, price);
  }
  return max_profit;
}

int main() {
  vector<int> prices1{};
  ASSERT_EQUALS(findMaxProfit(prices1), 0);

  vector<int> prices2{7,1,5,3,6,4};
  ASSERT_EQUALS(findMaxProfit(prices2), 5);

  vector<int> prices3{7,6,4,3,1};
  ASSERT_EQUALS(findMaxProfit(prices3), 0);

  vector<int> prices4{5,7,2,6};
  ASSERT_EQUALS(findMaxProfit(prices4), 4);
}
