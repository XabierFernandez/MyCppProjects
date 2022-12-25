#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    return (v1.size() == v2.size() &&
            std::equal(v1.begin(), v1.end(), v2.begin()));
}

// This function partitions given array and returns 
//  the index of the pivot.
int partition(vector<int> &vect, int p, int  r){
    // This code has been purposefully obfuscated,
    // as you will implement it yourself in next challenge    
    swap(vect[p],vect[r]);
    
    int i=p;
    for(int j=p;j < r; j++){
        if(vect[j]<=vect[r]){
            swap(vect[j],vect[i]);
            i++;
        }
        
    }
    swap(vect[r],vect[i]);
    return i;
};


void quickSort (vector<int> &vect, int l, int r) {
    if(l < r){
        int x = partition(vect, l, r);
        quickSort(vect, l, x-1);
        quickSort(vect, x+1, r);
        
    }
        
};

int main() {

    vector<int> vect = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    vector <int> vect1 = {2,3,5,6,7,9,10,11,12,14};
    quickSort(vect, 0, vect.size() - 1);
    std::cout << "vect=";   
    for (size_t i = 0; i < vect.size(); ++i) {
        std::cout << vect[i] << ' ';
    }
    std::cout << "\n";   
    std::cout << "vect1=";    
    for (size_t i = 0; i < vect1.size(); ++i) {
        std::cout << vect1[i] << ' ';
    }
    std::cout << "\n";

    if (isEqual(vect, vect1)){
        std::cout << "Both vectors are equal \n";
    }
    else{
        std::cout << "Both vectors are not equal \n";
    }
}


