#include <iostream>

using namespace std;

class Employee
{
private:
    /* data */
    string _name;
    string _lastname;
public:
    Employee(string name, string lastname){
        _name = name;
        _lastname = lastname; 
    };
    
    void printEmployeeDetails(){
        cout<< "Name: " << _name << "Last name: " << _lastname << endl;
    }
};

int main(){
    Employee employe01 = Employee("Xabier", "Fernandez");
    employe01.printEmployeeDetails();
}
