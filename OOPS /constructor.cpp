#include <iostream>
using namespace std;

class Employee{
    string name;
    int salary,empCode;
    public:
    Employee(){
        cout << "This is a default constructor" << endl;
    }
    Employee(string myName, int mySalary, int myCode){
        name = myName;
        salary = mySalary;
        empCode = myCode;
    }
    void display(){
    cout << name << endl;
    cout << salary << endl;
    cout << empCode << endl;

    }
};

int main(){
    Employee e1;
    Employee e("Sid", 5000000, 2932);
    e.display();
    return 0;
}
