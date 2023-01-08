#include <iostream>
#include <functional>
#include <thread>

using namespace std;

//free fucntion
void printNumbers(){
  for(int i = 0; i < 100; i++){
    cout << i << " ";
  }
  cout << endl;
}

//callable object
class Printer
{

public:
  void operator()(){
  for(int i = 0; i < 100000; ++i){
    if(!(i % 200)){
      cout << endl;
    }
    cout << "*";
  }
  }
};

function<void()> printOther = [](){
  for(int i = 0; i < 100000; ++i){
    if(!(i % 200)){
      cout << endl;
    }
    cout << "^";
  }
};

int main(){
  //lambda object
  auto printRevers = [](){
    for(int i = 100; i >= 0 ; --i){
      cout << i << " ";
    }
    cout << endl;
  };
  //synchronous excution start
  thread thr1 (printNumbers);
  thr1.join();

  thread thr2 (printRevers);
  thr2.join();
  //synchronous excution ends
  
  Printer print;
  thread thr3 (print);
  thr3.detach();

  thread thr4(printOther);
  thr4.detach();

  getchar();
  return 0;
}

