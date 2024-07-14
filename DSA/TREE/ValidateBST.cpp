bool solve(BinaryTreeNode<int> *root, int mini, int maxi){

    if(root==nullptr) return true;

    if (root->data >= mini && root->data <= maxi) {

      bool left = solve(root->left, mini, root->data);
      bool right = solve(root->right, root->data, maxi);
      return left&&right;
      
    } else
      return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root,INT_MIN,INT_MAX);
}
