#include <iostream>
using namespace std;

void get(string arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
}
int main(){
    int a,b,c;
    cin >> a;
    string arr1[a];
    get(arr1,a);
    cin >> b;
    string arr2[b];
    get(arr2,b);
    c = a*b;
    string arr3[c];
    static int k=0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr3[k+i] = arr1[i] + arr2[j];
            k++;
        }
        k--;
    }
    for (int i = 0; i < c; i++)
    {
        cout << arr3[i] << " " ;
    }
    
    
    return 0;
}