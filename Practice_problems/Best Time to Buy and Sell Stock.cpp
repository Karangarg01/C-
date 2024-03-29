class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            prof = max(prof, prices[i]-mini);
            mini = min(mini, prices[i]);
        }

        return prof;
    }
};
