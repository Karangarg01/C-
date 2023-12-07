class Solution{
    public:
long countSubarrays(int a[], int n, int L, int R)
    {
        long long int ans=0;
        int start=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=L && a[i]<=R)
            {
                p=i-start+1;
            }
            else if(a[i]>R)
            {
                start=i+1;
                p=0;
            }
            ans=ans+p;
        }
        return ans;
    }

};
