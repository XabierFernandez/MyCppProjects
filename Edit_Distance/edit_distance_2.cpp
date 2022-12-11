#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z);}

int edit_distance(const string &str1, const string &str2,int m, int n ) {
   // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return edit_distance(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(edit_distance(str1, str2, m, n - 1), // Insert
                 edit_distance(str1, str2, m - 1, n), // Remove
                 edit_distance(str1, str2, m - 1,
                          n - 1) // Replace
             );
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  int m = str1.size();
  int n = str2.size();
  std::cout << edit_distance(str1, str2, m, n) << std::endl;
  return 0;
}
