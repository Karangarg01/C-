    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);

        for(int i=0; i<n; i++){
            int a = A[i];
            int b = i+1;
            int c = n-1;
            
        while(b<c){
            if(A[b] + A[c] == X-a){
                return 1;
            }
            
            else if(A[b]+A[c] > X-a) c--;
            else b++;
        }
        }
        return 0;
    }
