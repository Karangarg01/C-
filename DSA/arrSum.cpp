#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size], sum = 0;
    cout << "Enter elements of array: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "The sum of elements is " << sum;
    return 0;
}