void merge(vector<int> &v, int s, int e){
    
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int index=s;
    //Copying the elements in new vector
    for(int i=0;i<len1;i++){
        first[i] = v[index++];
    }

    index= mid+1;
    for(int i=0;i<len2;i++){
        second[i] = v[index++];
    }

    //Merging the two Arrays
    int ind1=0, ind2=0;
    index = s;
    while(ind1<len1 && ind2<len2){
        if(first[ind1]<second[ind2]){
            v[index++] = first[ind1++];
        }

        else{
            v[index++] = second[ind2++];
        }
    }

    while(ind1<len1){
        v[index++] = first[ind1++];
    }

    while(ind2<len2){
        v[index++] = second[ind2++];
    }

    delete [] first;
    delete [] second;
}

void func(vector<int> &v, int s, int e){
    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;

    func(v,s,mid);          //Recurence call for left part 
    func(v,mid+1,e);        //Recurence call for right part 

    merge(v,s,e);
}
void mergeSort(vector < int > & arr, int n) {
    func(arr,0,n-1);
}
