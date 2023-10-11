#include <iostream>
using namespace std;

int main(){
    int arr[2] = {3,3};
    int tar = 6,a,b;
    for (int i = 0; i < 2; i++)
    {   
        for (int j = i+1; j < 2; j++)
        {
            
        if(tar - arr[i]==arr[j]){
            a=i;
            b=j;
        }
        }
        
    }
    cout << a << endl;
    cout << b << endl;
    
    return 0;
}