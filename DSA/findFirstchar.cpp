#include <iostream>
#include <string>
using namespace std;

void getElement(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int display(string arr[], int size, char ch)
{
    int count =0 ;
    for (int i = 0; i < size; i++)
    {
         if(arr[i][0] == ch)
        count++;
    }
    return count;
}
int main()
{
    int size;
    char ch;
    cin >> size;
    string arr[size];
    getElement(arr, size);
    cin >> ch;
    cout << display(arr, size,ch);
    return 0;
}