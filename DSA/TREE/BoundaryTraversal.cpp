void printLeft(TreeNode<int> *root, vector<int> &ans) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    ans.push_back(root->data);
    if(root->left) 
        printLeft(root->left, ans);
    else 
        printLeft(root->right, ans);
}

void printLeaf(TreeNode<int> *root, vector<int> &ans) {
    if(root == nullptr) 
        return;

    if(root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->data);
        return;
    }

    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
}

void printRight(TreeNode<int> *root, vector<int> &ans) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if(root->right) 
        printRight(root->right, ans);
    else 
        printRight(root->left, ans);

    ans.push_back(root->data);  // Push after recursive call to ensure bottom-up order
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> ans;

    if(root == nullptr) 
        return ans;

    ans.push_back(root->data);

    // Traverse the left boundary (excluding root and leaf nodes)
    printLeft(root->left, ans);

    // Traverse leaf nodes
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);

    // Traverse the right boundary (excluding root and leaf nodes)
    printRight(root->right, ans);

    return ans;
}
