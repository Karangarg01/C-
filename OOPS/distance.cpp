#include <iostream>
#include <cmath>
using namespace std;

struct distance
{
    int a,b,x,y;
    float dist(int a, int b, int x, int y){
        float l = float(sqrt(pow((a-x),2) + pow((b-y),2)));
        return l;
    }
};

int main(){
    struct distance d;
    cin >> d.a >> d.b ;
    cin >> d.x >> d.y ;
    cout << d.dist(d.a, d.b, d.x, d.y);

    return 0;
}