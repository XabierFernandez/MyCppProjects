#include <iostream>
#include <vector>

using namespace std;

int lnSrchRc(vector<int> vec, int low, int high ,int key){
    if (high < low){
        return -1;
    } 
    else if (vec[low] == key){
        return low;
    } 
    else{
        return lnSrchRc(vec, (++low), high, key);
    }    
}

int main() {
  vector<int> vec{0,1,2,3,4,23,16,59,35,9,10,11,103};
  int key{16};
  cout << lnSrchRc(vec, 0, vec.size(), key) << endl;
  return 0;
}