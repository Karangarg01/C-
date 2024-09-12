vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;

    if(root==nullptr)
        return ans;


    queue<BinaryTreeNode<int>*> q;

    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i=0; i<size; i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            if(i==0)
                ans.push_back(front->data);

            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }

    }

    return ans;
}
