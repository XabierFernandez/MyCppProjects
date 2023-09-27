#include <iostream>
#include <vector>

/*
Maximum Amount of Gold
Problem Introduction
You are given a set of bars of gold and your goal is to take as much gold as possible into
your bag. There is just one copy of each bar and for each bar you can either take it or not
(hence you cannot take a fraction of a bar).
*/

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
    // write your code here
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {

            dp[i][j] = dp[i - 1][j];
            if (w[i - 1] <= j)
            {
                int val = dp[i - 1][j - w[i - 1]] + w[i - 1];
                if (dp[i][j] < val)
                {
                    dp[i][j] = val;
                }
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
