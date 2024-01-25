#include<bits/stdc++.h>
using namespace std;
 

void sumRow(int arr[][4], int row){
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        cout << "Sum of row " << i << " is " << sum << endl;
    }
}

int maxSumrow(int arr[][4], int row, int col){
    int row_sum=INT_MIN;
    int row_ind = -1;
    for(int i=0;i<row;i++){
        int sum=0; 
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(row_sum<sum){
            row_sum = sum;
            row_ind=i;
        }
    }
    return row_ind;
}
int main(){
    int arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    cout << "Printing array:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    
    sumRow(arr,4);
    cout << "Row with max sum is " << maxSumrow(arr,4,4);
}
