#include <iostream>
#include <stack>
using namespace std;

void insBottom(stack<int> &st, int element){
    stack<int> temp;
    while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(element);
    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    
    
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);
    insBottom(st,10);
    while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }
    return 0;
}