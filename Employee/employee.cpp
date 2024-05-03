#include <iostream>

using namespace std;

class Employee {
private:
  /* data */
  string _name;
  string _lastname;
  int _age;

public:
  Employee(string name, string lastname, int age) {
    _name = name;
    _lastname = lastname;
    _age = age;
  }
  void printEmployeeDetails() {
    cout << "Name:" << _name << " Lastname:" << _lastname << " Age:" << _age
         << endl;
  }
};

int main() {
  Employee employe01 = Employee("Xabier", "Fernandez", 43);
  employe01.printEmployeeDetails();
}
