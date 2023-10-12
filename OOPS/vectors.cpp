#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int target, x=0;
    cout << "enter target: " << endl;
    cin >> target;

    for(int i=0; i<v.size(); i++){
        if(v[i]==target){
            x = i;
        }
    }
    cout << x << endl;
    return 0;
}