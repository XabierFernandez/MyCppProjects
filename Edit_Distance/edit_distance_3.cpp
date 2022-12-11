#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z);}

int edit_distance(const string &str1, const string &str2) {

  int m = str1.size();
  int n = str2.size();

  int ** dp = new int * [str1.size() + 1];

  for (int i = 0; i < str1.size() + 1; i++) {
    dp[i] = new int[str2.size() + 1];
  }

  dp[0][0] = 0;

  for (int i = 1; i < m + 1; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i < n + 1; i++) {
    dp[0][i] = i;
  }

  for (int i = 1; i < m + 1; i++) {

    for (int j = 1; j < n + 1; j++) {
      if (str1[m - i] == str2[n - j])
        dp[i][j] = dp[i - 1][j - 1];

      else {
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));

      }

    }

  }
  return dp[m][n];
  
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
