#include <iostream>
#include <thread>

using namespace std;


void printHello1(){
  cout << "hello thread 1/" << this_thread::get_id() << endl;
}
void printHello2(){
  cout << "hello thread 2/" << this_thread::get_id() << endl;
}

int main() {
  cout << "Start of single thread execution " << endl;
  printHello1();
  printHello2();
  cout << "End of single thread execution " << endl;
    cout << "------------------------------------------------" << endl;
  cout << "Start of multithread thread execution synchronous " << endl;
  thread th1(printHello1);
  th1.join();
  thread th2(printHello2);  
  th2.join();
  cout << "End of multithread thread execution synchronous " << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Start of multithread thread execution asynchronous " << endl;
  thread ath1(printHello1);
  thread ath2(printHello2);
  //daemon threads
  ath1.detach();    
  ath2.detach();
  this_thread::sleep_for(2s);
  cout << "End of multithread thread execution asynchronous" << endl;
  return 0;
}
