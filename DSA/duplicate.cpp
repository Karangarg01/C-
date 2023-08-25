#include <iostream>
#include <set>
using namespace std;

int main()
{
    string arr[] = {"apple", "banana", "orange", "grape", "banana","grape", "apple", "grape"};
    int n = sizeof(arr)/sizeof(arr[0]);
    set<string> s(begin(arr),end(arr));
    // set<string> s(arr, arr+n);
    // for(string i:arr){
    //     s.insert(i);
    // }
    for(string i:s){ 
        cout << i << " ";
    }
    cout << endl;
    // set<string> s;
    // arr<string, <n> > myarr;
    string myarr[n];
    int i = 0;
    for(string const &val: s){
        myarr[i] = val;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}