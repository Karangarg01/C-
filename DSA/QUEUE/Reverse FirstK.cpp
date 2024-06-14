class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        
        for(int i=0; i<k; i++){
            int element = q.front();
            st.push(element);
            q.pop();
        }
        
        while(!st.empty()){
            int element = st.top();
            q.push(element);
            st.pop();
        }
        
        int n = q.size() - k;
        for(int i=1; i<=n; i++){
            int t = q.front();
            q.pop();
            q.push(t);
        }
        
        return q;
    }
};
