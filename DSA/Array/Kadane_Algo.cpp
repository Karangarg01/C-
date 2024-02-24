    long long maxSubarraySum(int arr[], int n){
        
        long sum=0;
        long long maxi = arr[0];
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum>maxi) maxi = sum;
            if(sum<0) sum=0;
        }
        
        return maxi;
        
    }
