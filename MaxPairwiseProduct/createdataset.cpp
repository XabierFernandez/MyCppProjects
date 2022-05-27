#include <iostream>
#include <fstream>
using namespace std;

int main () {
  fstream datasetfile;
  string filename("dataset.txt");
  long int n = 2000000;

  datasetfile.open (filename);  
  for (int i = 1; i <= n; ++i) {
      datasetfile << i << " ";
  }  
  datasetfile.close();

  return 0;
}