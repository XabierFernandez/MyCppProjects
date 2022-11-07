#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h>

using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::min;



//############################################################################
template<typename T>
vector<T> s(vector<T> const &v, int m, int n) {
   auto first = v.begin() + m;
   auto last = v.begin() + n + 1;
   vector<T> vector(first, last);
   return vector;
}
//############################################################################
template<typename T>
void show(vector<T> const &v) {
   for (auto i: v) {
      cout << i << endl;
   }
   cout << endl;
}

//############################################################################
bool sortByFirst(const pair<int,int> &a, const pair<int,int> &b)
{
  return (a.first < b.first);
}
//############################################################################
bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b)
{
  return (a.second < b.second);
}
//############################################################################
double dist(pair<int,int> point1, pair<int,int> point2)
{
  return sqrt( (point1.first - point2.first)*(point1.first  - point2.first) +
                (point1.second - point2.second)*(point1.second - point2.second));
}
//#############################################################################
double min(double x, double y) 
{ 
  return (x < y)? x : y; 
} 
//#############################################################################
double naive_find_minimal_distance(vector<pair<int,int>> points, int n) 
{ 
  double min = DBL_MAX; 
  for (int i = 0; i < n; ++i){
    for (int j = i+1; j < n; ++j){
      if (dist(points[i], points[j]) < min){
        min = dist(points[i], points[j]); 
      }  
    }  
  }          
      
  return min; 
} 
//###############################################################################
double stripClosest(vector<pair<int,int>> strip, int n, double d) 
{ 
  double min = d;  
  for (int i = 0; i < n; ++i) 
    for (int j = i+1; j < n && (strip[j].first - strip[i].second) < min; ++j) 
      if (dist(strip[i],strip[j]) < min) 
        min = dist(strip[i], strip[j]);   
  
  return min; 
} 
//##############################################################################
double find_minimal_distance(vector<pair<int,int>> points_x, vector<pair<int,int>> points_y, int n){ 
  //================================================================
  if (n <= 3) return naive_find_minimal_distance(points_x, n); 
  //================================================================
  int mid = n/2; 
  pair<int,int> midPoint = points_x[mid]; 
  vector<pair<int,int>> Pyl(mid+1);   
  vector<pair<int,int>> Pyr(n-mid-1);  
  int li = 0, ri = 0;   
  for (int i = 0; i < n; i++) 
  { 
    if (points_y[i].first <= midPoint.first) 
        Pyl[li++] = points_y[i]; 
    else
        Pyr[ri++] = points_y[i]; 
  } 
  //=================================================================
  double dl = find_minimal_distance(points_x, Pyl, mid);
  //vector<pair<int,int>> points_x_temp((points_x.begin() + mid) , (points_x.begin() + n + 1));
  vector<pair<int,int>> points_x_temp = s(points_x, mid, n+1);
  double dr = find_minimal_distance(points_x_temp, Pyr, n-mid); 
  double d = min(dl, dr);
  //=================================================================
  vector<pair<int,int>> strip(n);
  int j = 0; 
  for (int i = 0; i < n; i++) 
    if (abs(points_y[i].first - midPoint.first) < d){
      strip[j] = points_y[i], j++; 
    }       
  
  return  min(d, stripClosest(strip, j, d)); ;
}
//##############################################################################
double minimal_distance(vector<int> x, vector<int> y, int n ){
  //write your code here
  vector<pair<int,int>> points(n);
  //============================================================================
  for(int i = 0; i < n; i++){
   points[i].first = x[i];
   points[i].second = y[i];
  }
  /* for(int i = 0; i < n; i++){
    cout << "points[" << i << "]:" << points[i].first << "," << points[i].second << endl;
  } */
  //===============================================================================
  vector<pair<int,int>> points_sort_x(points);
  vector<pair<int,int>> points_sort_y(points);
  //===============================================================================
  sort(points_sort_x.begin(),points_sort_x.end(), sortByFirst);
  sort(points_sort_y.begin(),points_sort_y.end(), sortBySecond);
  //===============================================================================

  /* for(int i = 0; i < n; i++){
    cout << "points[" << i << "]:" << points[i].first << "," << points[i].second << endl;
    cout << "points_x[" << i << "]:" << points_sort_x[i].first << ","  << points_sort_x[i].second << endl;
    cout << "points_y[" << i << "]:" << points_sort_y[i].first << ","  << points_sort_y[i].second << endl;
  } */

  return find_minimal_distance(points_sort_x, points_sort_y, n);

}
//=================================================================================
int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  /* for(int i = 0; i < n; i++){
    cout << "x[" << i << "]:" << x[i] << ", y[" << i << "]:" << y[i] << endl;
  } */

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y, n) << "\n";
  
}
