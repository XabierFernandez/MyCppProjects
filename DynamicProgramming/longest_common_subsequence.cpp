#include <iostream>
#include <vector>
#include <bits/stdc++.h>  


int lcs(int m, char *x, int n, char *y) 
{ 
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

int max(int a, int b) 
{  
    return (a > b) ? a : b;  
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

