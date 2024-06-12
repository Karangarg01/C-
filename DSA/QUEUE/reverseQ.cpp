class Solution
{
    public:
    void stackRev(stack<int> &st, queue<int> &q){
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        
    }
    queue<int> rev(queue<int> q)
    {
        stack<int> st;
        stackRev(st,q);
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }

// Recursive Method
void func(queue<int> &q){
        
        if(q.empty()){
            return;
        }
        
        int a = q.front();
        q.pop();
        
        func(q);
        q.push(a);
    }
    
    queue<int> rev(queue<int> q)
    {
        func(q);
        return q;
    }
};
