#include <iostream>

int largestProductOfDigit(int a, int b) {
  int largest = 0;
  int largestProduct =0;

 if(a<10 && a>=100 && b<10 && b>=100){
      return largest;
  }

  for (int i = a; i <= b; i++) {
    int second = i % 10;
    int first = (i - second) /10; 
    if ((first * second) > largestProduct) {
        largest = i;
        largestProduct = first * second;
    }
  }
  return largest;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << largestProductOfDigit(a, b) << std::endl;
  return 0;
}