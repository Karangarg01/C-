class Solution {
public:

    void solve(string digits, string output, int index, string mapping[], vector<string> &ans){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        int element = digits[index] - '0';  // Converting Char to int
        string value = mapping[element];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, mapping, ans);
            output.pop_back();
        }

    }
    
    vector<string> letterCombinations(string digits) {
        
        string output = "";
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;

        solve(digits, output, index, mapping, ans);
        return ans;
    }
};
