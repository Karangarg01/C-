#include <iostream>
using namespace std;

void getElement(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
         if(arr[i]!=0)
        cout << arr[i] << " ";
    }
}
int main(){
    
    int size;
    cin >> size;
    int arr[size];
    getElement(arr, size);
    display(arr,size);
    return 0;
}
