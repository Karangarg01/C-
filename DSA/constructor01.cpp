#include <iostream>
using namespace std;

class rectangle{
    int length ,width ;
    public:
    rectangle(){
        cout << "This is a default constructor" << endl;
    }
    rectangle(int mylength , int mywidth){
        length  = mylength ;
        width  = mywidth;
    }
    void area(){
    cout << length*width  << endl;
    }
    void perim(){
    cout << 2*(length+width)  << endl;
    }
};

int main(){
    rectangle obj1;
    rectangle obj(50, 5);
    obj.area();
    obj.perim();
    return 0;
}