#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());

  sort(starts.begin(),starts.end());  
  sort(ends.begin(),ends.end());  

  for (size_t i = 0; i < points.size(); i++) {
    size_t j, k;
      for ( j = 0; j < starts.size(); j++) {
        if(starts[j] > points[i]){
          break;
        }
      } 

      for ( k = 0; k < starts.size(); k++) {
        if(ends[k] >= points[i]){
          break;
        }
      } 
      cnt[i] = j - k;      

  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
