class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return false;

        sort(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i++){
            int j=i-1;

            if(nums[i]==nums[j]) return true;
        }

        return false;
    }
};
