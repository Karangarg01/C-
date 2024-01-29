#include <iostream>
using namespace std;

int main()
{
    int row, col;
    
    cout << "Enter number of rows: ";
    cin >> row;
    
    cout << "Enter number of cols: ";
    cin >> col;
    
    int **arr = new int*[row]; // Created n rows of int*
    
    for(int i=0;i<row;i++){
        arr[i] = new int[col];  // Created m cols for each arr
    }
    
    // Taking input for array elements
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> arr[i][j];
        }
    }
    
    // Printing array elements
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Releasing Memory
    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    
    delete[] arr;
    
    return 0;
}
