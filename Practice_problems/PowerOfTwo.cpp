class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = 0;
        long ans = INT_MIN;
        while(ans<=n){
        ans = pow(2,x);
        if(ans==n){
            return true;
        }
        x++;
        }
        return false;
    }
};
