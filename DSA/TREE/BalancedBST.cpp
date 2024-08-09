void inorder(TreeNode<int>* root, vector<int> &v){
    if(root==nullptr) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right,v);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &v){

    if(s>e) return nullptr;

    int mid = s+(e-s)/2;

    TreeNode<int>* root = new TreeNode<int>(v[mid]);
    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);

    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    
    vector<int> v;
    inorder(root, v);

    return inorderToBST(0, v.size()-1, v);
}


