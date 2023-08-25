#include <iostream>
// #include <ctime>
using namespace std;

class time{
    int h,m,s;
    public:
        void set(int, int, int);
        void disp(){
            cout << h << ":" << m << ":" << s;
        }

};
void time :: set(int a, int b, int c){
    h = a;
    m = b;
    s = c;
}
int main(){
    // time_t now = time(0);
    // char* dt = ctime(&now);
    // cout << dt;
    // int i,j,a,b;

    // scanf("%02d:%02d", &i, &j);
    // scanf("%02d:%02d", &a, &b);
    // cout << i-a<< ":" << j-b;

    time t;
    t.set(21,35,10);
    t.disp();
   

    return 0;
}