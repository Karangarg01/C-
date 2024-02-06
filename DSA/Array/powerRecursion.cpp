#include <iostream>
using namespace std;

int power(int n, int x){
    if(x==0) 
        return 1;
    
    if(x==1)
        return n;
    
    int ans = power(n,x/2);
    
    if(x%2==0){
        ans*ans;
    }
    else{
        ans = n*ans*ans;
    }
    return ans;
}
int main()
{
    int a = 4;
    int ans = power(6,3);
    cout << ans;

    return 0;
}
