vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> v;
    
    for(int i=d; i<arr.size(); i++){
        v.push_back(arr[i]);
    }
    
    for(int i=0; i<d; i++){
        v.push_back(arr[i]);
    }
    return v;
}
