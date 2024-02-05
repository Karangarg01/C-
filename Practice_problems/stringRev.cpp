#include <bits/stdc++.h> 

void func(string &s, int i, int j){
	if(i>j)
		return;
	
	swap(s[i++],s[j--]);
	func(s,i,j);
}
string reverseString(string str)
{
	func(str,0,str.length()-1);
	return str;

}
