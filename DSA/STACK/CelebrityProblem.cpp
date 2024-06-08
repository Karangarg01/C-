class Solution 
{
    private:
        bool knows(vector<vector<int> >& M, int a, int b){
            if(M[a][b]==1) return 1;
            else return 0;
        }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }
            
            else{
                st.push(a);
            }
        }
        
        int candidate = st.top();
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++){
            if(M[candidate][i] == 0) zeroCount++;
        }
        
        if(zeroCount!=n) return -1;
        
        int oneCount = 0;
        
        for(int i=0; i<n; i++){
            if(M[i][candidate]==1) oneCount++;
        }
        
        if(oneCount != n-1) return -1;
        
        return candidate;
        
    }
};
