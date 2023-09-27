#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int countOfNumbers = exp.size() / 2 + 1;
  long long minArray[countOfNumbers][countOfNumbers];
  long long maxArray[countOfNumbers][countOfNumbers];
  std::memset(minArray, 0, sizeof(minArray)); // Initialize to 0
  std::memset(maxArray, 0, sizeof(maxArray));

  for (int i = 0; i < countOfNumbers; i++) {
    minArray[i][i] = std::stoll(exp.substr(2 * i, 1));
    maxArray[i][i] = std::stoll(exp.substr(2 * i, 1));
  }

  for (int s = 0; s < countOfNumbers - 1; s++) {
    for (int i = 0; i < countOfNumbers - s - 1; i++) { // MianAndMax algorithm
      int j = i + s + 1;
      long long minVal = LLONG_MAX; // + infinity or a positive largest number
      long long maxVal = LLONG_MIN; // - infinity or a negative largest number

      for (int k = i; k < j; k++) {
        char op = exp[2 * k + 1];
        long long a = eval(minArray[i][k], minArray[k + 1][j], op); // m(i,k) op(k) m(1,j)
        long long b = eval(minArray[i][k], maxArray[k + 1][j], op); // m(i,k) op(k) M(k+1,j)
        long long c = eval(maxArray[i][k], minArray[k + 1][j], op); // M(i,k) op(k) m(k+1,j)
        long long d = eval(maxArray[i][k], maxArray[k + 1][j], op); // M(i,k) op(k) M(k+1,j)
        minVal = std::min(minVal, std::min(a, std::min(b, std::min(c, d)))); //min = min(minVal,a,b,c,d)
        maxVal = std::max(maxVal, std::max(a, std::max(b, std::max(c, d)))); //max = max(maxVal,a,b,c,d)
      }

      minArray[i][j] = minVal;
      maxArray[i][j] = maxVal;
    }
  }

  return maxArray[0][countOfNumbers - 1];

}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
