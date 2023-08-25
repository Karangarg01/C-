#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){
    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target){
            return 1;
            ind = i;
        }
        else return 0;
    }
    return ind;
    
}
int main(){
    int arr[]= {1,32,43,22,32,19};
    int n;
    n = sizeof(arr)/sizeof(int);
    int s = linearSearch(arr, n, 32);
    if(s) cout << s;
    return 0;
}