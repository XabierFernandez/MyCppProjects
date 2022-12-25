#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int lcs2(vector<int> &x, vector<int> &y) {
  //write your code here
  //-----------------
  int m = x.size();
  int n = y.size();
  //-----------------
  int dp[m + 1][n + 1]; 
  int i, j; 
  
  for (i = 0; i <= m; i++) 
  { 
      for (j = 0; j <= n; j++) 
      { 
          if(i == 0 || j == 0) 
              dp[i][j] = 0; 
          else if (x[i-1] == y[j-1]) 
              dp[i][j] = dp[i-1][j-1] + 1; 
          else
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
      } 
  } 

  return dp[m][n]; 
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }

  cout << lcs2(a, b) << endl;
}
