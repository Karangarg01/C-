#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> v(n);

    st.push(-1);
    for(int i=n-1; i>=0; i--){
        int curr = arr[i];

        while(st.top()>=curr){
            st.pop();
        }

        v[i] = st.top();

        st.push(curr);
    }

    return v;
}
