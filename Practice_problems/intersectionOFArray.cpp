#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> v;
	int k = 0;
	int l = 0;
	while(k<n && l<m){
			if(arr1[k]<arr2[l]){
				k++;
			}
			else if(arr1[k]>arr2[l]){
				l++;
			}

			if(arr1[k]==arr2[l]){
				v.push_back(arr1[k]);
				k++;
				l++;
			}
	}
	return v;
}
