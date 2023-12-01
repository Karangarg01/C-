class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int l = nums1.size();
        int m = nums2.size();
        int k = nums1.size() + nums2.size();

        for(int i=0;i<l;i++){
            v.push_back(nums1[i]);
        }

        for(int j=0;j<m;j++){
            v.push_back(nums2[j]);
        }

        sort(v.begin(),v.end());
        if(k%2==0){
            int a = (k/2);
            float ind = (v[a-1] + v[a]);
            return ind/2;
        }
        else{
            int a = (k+1)/2;
            float ind = v[a-1];
            return ind;
        }

    }
};
