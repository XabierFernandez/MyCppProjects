#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int lcs_3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int n = a.size();
  int m = b.size();
  int o = c.size();
  int dp[n +1][m +1][o +1];
  int i, j, k;

  for (i = 0; i <= n; i++) 
  { 
      for (j = 0; j <= m; j++) 
      { 
        for (k = 0; k <= o; k++){
          if(i == 0 || j == 0 || k == 0) 
              dp[i][j][k] = 0; 
          else if (a[i-1] == b[j-1] && a[i-1] == c[k-1]) 
              dp[i][j][k] = dp[i-1][j-1][k-1] + 1; 
          else
              dp[i][j][k] = max(max(dp[i-1][j][k], 
                                dp[i][j-1][k]),
                                dp[i][j][k-1]); 
        }
          
      } 
  } 

  return dp[n][m][o];
}

int main() {
  size_t an;
  cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    cin >> a[i];
  }
  size_t bn;
  cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    cin >> b[i];
  }
  size_t cn;
  cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
   cin >> c[i];
  }
  cout << lcs_3(a, b, c) << endl;
}
