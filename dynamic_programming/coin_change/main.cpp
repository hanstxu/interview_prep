#include "../../test.h"
#include <algorithm>
using namespace std;

/**
 * Given an array of coins of different denominations and
 * a total amount, return the fewest number of coins
 * needed to make that amount.
 *
 * Return -1 if the amount cannot be made up by any combination
 * of coins.
 */
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }

  vector<int> denominations(amount + 1, -1);

  for (int i = 1; i <= amount; ++i) {
    for (auto coin: coins) {
      if (coin > i) {
        continue;
      }

      if (coin == i) {
        denominations[i] = 1;
        break;

      } else if (denominations[i - coin] != -1) {
        if (denominations[i] == -1) {
          denominations[i] = denominations[i - coin] + 1;

        } else {
          denominations[i] = min(denominations[i], denominations[i - coin] + 1);
        }
      }
    }
  }

  return denominations[amount];
}

int main() {
  vector<int> coins_1 = vector<int>{1};
  vector<int> coins_2 = vector<int>{2};
  vector<int> coins_3 = vector<int>{1,2,5};

  ASSERT_EQUALS(coinChange(coins_1, 0), 0);
  ASSERT_EQUALS(coinChange(coins_1, 1), 1);
  ASSERT_EQUALS(coinChange(coins_1, 2), 2);
  ASSERT_EQUALS(coinChange(coins_2, 3), -1);
  ASSERT_EQUALS(coinChange(coins_3, 11), 3);
}
