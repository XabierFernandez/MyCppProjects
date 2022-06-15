#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  int n = values.size();
  double density_prev = 0.0;
  double density_current = 0.0;
  double density_next = 0.0;
  vector<double> density_ratio(n, 0);
  vector<int> index(n, 0);

  for (size_t i = 0; i < n; i++)
  {
    density_ratio[i] = (double)(values[i] / (double)weights[i]);
    index[i] = i; 
  }

  for (size_t i = 0; i < n - 1; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (density_ratio[j] > density_ratio[i]) {
        double temp = density_ratio[i];
        density_ratio[i] = density_ratio[j];
        density_ratio[j] = temp;
        //================================
        int  temp1 = index[i];
        index[i] = index[j];
        index[j] = temp1;
      }
    }
  }

  for (size_t i = 0; i < n; i++){
    std::cout << "density_ratio=" << density_ratio[i] << " index=" << index[i] << std::endl;
  }

  for (size_t i = 0; i < n; i++){
    if (capacity <= 0) break;

    if(weights[index[i]] <= capacity){
      value += values[index[i]] ;
      capacity -= weights[index[i]];
    }
    else{  
      double fraction = values[index[i]]  * ((double)capacity / (double)weights[index[i]]);      
      value += fraction; 
      capacity = 0;     
    }
  }  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
