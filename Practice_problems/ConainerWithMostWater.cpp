class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;

        int area, ans=0;
        while(l<r){
            int len = r-l;
            int wid = min(height[l],height[r]);
            area = len*wid;
            ans = max(ans,area);
            
            if(height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};
