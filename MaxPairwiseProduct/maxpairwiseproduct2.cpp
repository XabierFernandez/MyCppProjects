#include <iostream>
#include <vector>
#include <stdint.h>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
  int64_t result = 0;
  int n = numbers.size();
  
  if(n>=2){
  int index1 = 0;
  int index2 = 0;

  for (int i = 1; i < n; ++i) {
	if(numbers[i]>numbers[index1]){
    	index1 = i;
    }
  }
  
  if(index1==0){
   index2=1;
  }else{
   index2=0;
  }            
       
  for (int i = 0; i < n; ++i) {
	if((i!=index1) && (numbers[i]>numbers[index2])){
    	index2 = i;
    }
  }

 result = numbers[index1] * numbers[index2];
 }
 else if(n==2){
  return (numbers[0] * numbers[0]);
 }
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int64_t result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
