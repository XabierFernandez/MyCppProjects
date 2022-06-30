#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), [](const Segment &seg_a, const Segment &seg_b) -> bool {
        return seg_a.end < seg_b.end;
  });

  int point = segments[0].end;
  points.push_back(point);

  for (size_t i = 1; i < segments.size(); ++i) {
    if (point < segments[i].start || point > segments[i].end) { 
      point = segments[i].end; 
      points.push_back(point); 
    }
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
