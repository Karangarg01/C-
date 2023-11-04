#include <iostream>
#include <set>
using namespace std;

int main()
{
    string arr[] = {"apple", "orange", "apple", "grape", "banana", "grape", "orange"};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << n;
    int x = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] == arr[j])
            {
                x = j;
            }
        }
        if (arr[i] == arr[x])
            continue;
        else
            cout << arr[i] << " " << endl;
    }

    return 0;
}