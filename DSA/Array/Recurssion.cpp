#include <iostream>
using namespace std;

int sum(int arr[], int size){
    
    int a = 0;
    if(size==0){
        return 0;
    }
    
    if(size==1){
        return arr[0];
    }
    
    int remPart = sum(arr+1, size-1);
    
    int s = arr[0] +remPart;
    return s;
    
}

bool LinearSearch(int *arr, int size, int key){
    if(size==0) 
        return false;
        
    if(arr[0]==key)
        return true;

    else {

    bool remPart = LinearSearch(arr+1,size-1, key);
    return remPart;
    }
}

bool BinarySearch(int *arr, int key, int s, int e){
    if(s>e)
        return false ;
        
    int mid = s + (e-s)/2;
    
    if(arr[mid] == key)
        return true;
    
    else if(arr[mid]>key){
        return BinarySearch(arr, key, s, mid-1);
    }
    
    else{
        return BinarySearch(arr, key, mid+1, e);
       
    }
}
int main()
{
    int arr[5] = {2,5,7,8,10};
    int size = 5;
    
    // int ans = sum(arr,size);
    // cout << ans;
    // bool ans = LinearSearch(arr,5,10);
    // cout << ans;
    
    
    bool ans = BinarySearch(arr,10, 0, 4);
    
    if(ans) cout << "Present";
    else cout << "Absent";
    return 0;
}
