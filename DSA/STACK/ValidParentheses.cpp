bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char exp = s[i];

        if(exp == '(' || exp == '{' || exp == '['){
            st.push(exp);
        }

        else{
            if (!st.empty()) {
              char top = st.top();
              if (exp == ')' && top == '(' || exp == '}' && top == '{' ||  exp == ']' && top == '[')
                    st.pop();
              else {
                    return false;
              }
            } else
              return false;
        }
    }

    if(st.empty()) return true;
    else return false;

}
