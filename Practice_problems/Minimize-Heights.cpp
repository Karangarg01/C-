   int getMinDiff(int arr[], int n, int k) {
        
   sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        
        int largest=arr[n-1]-k;
        int smallest=arr[0]+k;
        int mi,ma;
        
        for(int i=1;i<n;i++){
          mi=min(smallest,arr[i]-k);
          ma=max(largest,arr[i-1]+k);
          if(mi<0) 
          continue;
          ans=min(ans,ma-mi);
        }
        return ans;
    }
