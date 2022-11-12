#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

void printVector(vector<int> v){
  for(int i= 0; i < v.size();i++) {
   cout << v[i] << endl;
  }
}

vector<int> optimal_sequence_dp(int n) {
  std::vector<int> sequence_temp = {0, 1};
  std::vector<int> sequence;
  std::vector<int> mem = {-1,0};
  int result_1 = 0;
  int result_2 = 0;
  int result_3 = 0;
 
  for(int i=2; i<n+1; i++){
    result_1 = n;
    result_2 = n;
    result_3 = n;
    if(i % 2 == 0)result_2 = mem[i/2];
    if(i % 3 == 0)result_3 = mem[i/3];
    if(i - 1 >= 0)result_1 = mem[i-1];

    mem.push_back(min(result_3+1, min(result_2+1, result_1+1)));
    
    if (result_3 <= min(result_2, result_1)){
      sequence_temp.push_back(i/3);
    }
    else if(result_2 <= min(result_3, result_1)){
      sequence_temp.push_back(i/2);
    }else if(result_1 <= min(result_3, result_2)){
      sequence_temp.push_back(i-1);
    }
  }
  sequence.push_back(n);
  //cout << mem[n] << endl;
  //printVector(sequence_temp);

  while(n > 1){
    sequence.push_back(sequence_temp[n]);
    n = sequence_temp[n];
    //cout << "n: " << n << endl;
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
