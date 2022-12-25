#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z);}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  if(str1.empty()) return str2.size();
  if(str2.empty()) return str1.size();

  /* If last characters of two strings are same, nothing
	   much to do. Ignore last characters and get count for
	   remaining strings
  */

	if(str1[str1.size()-1] == str2[str2.size()-1]){
    string s1 = str1.substr(0, str1.size()-1);
    string s2 = str2.substr(0, str2.size()-1);
    return edit_distance(s1, s2);
  }		

	/* If last characters are not same, consider all three
	   operations on last character of first string, recursively
	   compute minimum cost for all three operations and take
	   minimum of three values.
  */
  string s1 = str1.substr(0, str1.size()-1);
  string s2 = str2.substr(0, str2.size()-1);

  int temp_min = min(edit_distance(str1, s2), //Insert
                    edit_distance(s1, str2)); //Remove

	return 1 + min(temp_min, 
                 edit_distance(s1, s2) // Replace
                 );
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
