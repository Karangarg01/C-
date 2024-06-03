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
void solve(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
    
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
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
