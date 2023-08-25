// #include <iostream>
// #include <climits>
// using namespace std;

// int getMax(int arr[], int size){
//     int max = INT_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
        
//     }
//     return max;
// }
// int main(){
//     int size;
//     cin >> size;
//     int arr[100];
//     for (int i = 0; i<size; i++){
//         cin >> arr[i];
//     }
//     cout << "Greatest number is: " << getMax(arr,size);
//     return 0;
// }
#include <iostream>
using namespace std;

int main(){
    int arr[10] = {10,50,60,42,15}, index = 2, element = 100;
    int size = sizeof(arr[10])/sizeof(int);
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];   
        
    }
    size++;
    arr[index] = element;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}