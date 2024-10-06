#include <iostream>
#include <vector>
#include <bits/stdc++.h>  

using namespace std;
using std::vector;

int get_change(int m) {
  //write your code here
  vector<int> solutions(m+1, INT_MAX);
  vector<int> coins = {1, 3, 4};
  solutions[0] = 1;    

  for (int i = 1; i <= m; i++) {
		for (int c = 0; c < coins.size(); c++) {
			if (i >= coins[c]) {
				if (solutions[i - coins[c]] != INT_MAX && solutions[i - coins[c]] + 1 < solutions[i])
					solutions[i] = solutions[i - coins[c]] + 1;
			}
		}
	}

 return solutions[m];

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

