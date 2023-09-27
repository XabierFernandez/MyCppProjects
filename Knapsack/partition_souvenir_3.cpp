// Copyright 2023 Xabier Fernandez
#include <iostream>
#include <numeric>
#include <vector>

/*
Partitioning Souvenirs
You and two of your friends have just returned back home after visiting various
countries. Now you would like to evenly split all the souvenirs that all three
of you bought.
*/
using std::vector;

int partition3(const vector<int> &A) {
  // write your code here
  int total_sum = std::accumulate(A.begin(), A.end(), 0);
  // If the total sum is not divisible by W, it can't be partitioned.
  if (total_sum % 3 != 0) {
    return 0;
  }

  int target_sum = total_sum / 3;
  int n = A.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(target_sum + 1, false));

  // Initialize the DP table.
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }

  // Fill the DP table.
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= target_sum; ++j) {
      if (A[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Result is 1 if it's possible to partition into W subsets with equal sums.
  return dp[n][target_sum];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
