#include<iostream>
using namespace std;

class emp{
    private:
        int a,b,c;
    public:
        int d,e;
    void setData(int x, int y, int z);
    void getData(){
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};
void emp:: setData(int x, int y, int z){
    a = x;
    b = y;
    c = z;
}
int main(){

emp me;
me.d = 96;
me.e = 43;
me.setData(20,34,55);
me.getData();

}