#include <bits/stdc++.h> 

void sortFunc(stack<int> &stack, int n){

	if(stack.empty() || (!stack.empty()&& n>stack.top())){
		stack.push(n);
		return;
	}

	int top = stack.top();
	stack.pop();
	sortFunc(stack, n);
	stack.push(top);


}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	sortFunc(stack, num);
}
