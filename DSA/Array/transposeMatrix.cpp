#include <iostream>
using namespace std;

void getInput(int** arr, int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }
}

void print(int** arr, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0; j<cols; j++){
           cout << arr[i][j] << " ";
        }cout << endl;
    }
}

void transpose(int** &arr, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=i+1; j<cols; j++){
           swap(arr[i][j],arr[j][i]);
        }
    }    
}

int main()
{
    int rows,cols;
    cin >> rows >> cols;
    int** arr = new int*[rows];
    
    for(int i=0;i<rows;i++){
        arr[i] = new int[cols];
    }
    
    getInput(arr,rows,cols);
    cout << "Printing original array" << endl;
    print(arr,rows, cols);
    
    transpose(arr,rows,cols);
    cout << "Transpose of the array" << endl;
    print(arr,rows,cols);
    
    for(int i=0; i<rows; i++){
        delete[] arr[i];
    }
    
    delete[] arr;
    return 0;
}
