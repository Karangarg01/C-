class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        bool flag = true;
        int l=0,k=1;
        while(k<N){
           if(arr[l]>=arr[k]){
               flag = false;
               break;
            }
            l++;
            k++;
        }
        if(flag) return 1;
        else return 0;
    }
};
