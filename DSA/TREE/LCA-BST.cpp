TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root==nullptr) return nullptr;

    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right,P,Q);
    }

    else if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }
    else return root;
}
