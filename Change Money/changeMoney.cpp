#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  int k  = m;
  while (k > 0){
      if(k >= 10){
        k = k - 10;
      }
      else if(k >= 5){
        k = k - 5;   
      }
      else if(k < 5){
        k = k - 1; 
      }
      n = n + 1;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
