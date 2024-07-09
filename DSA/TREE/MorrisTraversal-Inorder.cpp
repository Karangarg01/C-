class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the inorder predecessor of curr
                TreeNode* pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }

                // Establish a temporary thread to the inorder predecessor
                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } 
                // Remove the temporary thread and visit the current node
                else {
                    pre->right = nullptr;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                v.push_back(curr->val);
                curr = curr->right;
            }
        }

        return v;
    }
};
