int missingNumber(vector<int>& array, int n) {
  sort(array.begin(),array.end());
  int ans = 0;
  for(int i=1;i<=n;i++){
      ans = ans^i;
  }
  for(int i=0;i<n-1;i++){
      ans = ans^array[i];
  }
  
  return ans;
}
