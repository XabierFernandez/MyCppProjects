//NamedStudent - this program demostrates the use
//of a constructors with arguments
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Student{
    protected:
        char*   pszName;
        int     nID;
    public:
        Student(const char* pszNewName, int nNewID){
            cout << "Constructing " << pszNewName << endl;
            int nLength = strlen(pszNewName) + 1;
            pszName = new char[nLength];
            strcpy(pszName, pszNewName);
            nID = nNewID;
        }
        
        ~Student(){
            cout << "Destructing " << pszName << endl;
            delete[] pszName;
            pszName = nullptr;
        }

        const char* getName(){
            return pszName;
        }

        int getID(){
            return nID;
        }

};

Student* fn(){
    //create a student and initialize it
    cout << "Constructing a local student in fn()" << endl;
    Student student("Flavia Rovella", 007);
    //display the student's name
    cout << "The student's name is " << student.getName() << endl;
    //allocate one off of the heap
    cout << "Allocating a Student from the heap" << endl;
    Student *ps = new Student("Xabier Fernandez", 001);
    //display this student's name
    cout << "The second student's name is " << ps->getName() << endl;
    cout << "Returning from fn()" << endl;

    return ps;
}

int main(int nNumberOfArgs, char* pszArgs[]){
    //call the function that creates student objects
    cout << "Calling fn()" << endl;
    Student* ps = fn();
    cout << "Back in main()" <<endl;
    //delete the object returned by fn()
    delete ps;
    ps = nullptr;
    //wait until user is ready before terminating program
    //to allow the user to see the program results
    cout << "Press Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();

    return 0;
}
