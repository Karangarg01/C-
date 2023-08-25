#include<iostream>
using namespace std;

int main(){

    int row, col;
    cout << "Enter row and column number: ";
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            
            cout << j ;

        }

        
       cout << endl;
    }
    
    return 0;
}
/*
 for(auto i : arr){
    cout << i << endl;
 }
*/