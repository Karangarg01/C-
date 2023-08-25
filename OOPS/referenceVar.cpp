#include <iostream>
using namespace std;


/*
using & in front of name for aliasing name of a var name is named as n ; no new memory is allocated
if the value of n is changed then original value of name will also change
*/

void test(int &n){
    n++;
    cout << "value of n from test method is: " << n << endl;
}
int &test2(int n){ 
    // int &test2 and int& test are same
    int num = n;
    int &ans = num;
    return ans;
}
int main(){
    int name = 5;
    int &n = name; 
    cout << n;

    return 0;
}
