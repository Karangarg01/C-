class Solution {
    
  private:
        
    pair<int, int> calcDiameter(Node* root){
        
        if(root==nullptr){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> left = calcDiameter(root->left);
        pair<int, int> right = calcDiameter(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;
        
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
        
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        pair<int,int> d = calcDiameter(root);
        return d.first;
    }
};
