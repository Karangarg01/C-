void traverse(BinaryTreeNode<int>* root, vector<int> &v, queue<BinaryTreeNode<int>*> &q){
    
    if(root==nullptr) return;


    v.push_back(root->data);
    if(root->left) q.push(root->left);

    traverse(root->right, v,q);
}

void solve(BinaryTreeNode<int>* root, vector<int>&v, queue<BinaryTreeNode<int>*> &q){

    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        traverse(front, v, q);
    } 

    sort(v.begin(), v.end());   
}

bool check(vector<int> v1, vector<int> v2){

    if(v1.size()!=v2.size()) return false;

    for(int i=0; i<v1.size(); i++){
        if(v1[i] != v2[i]) return false;
    }

    return true;
}
bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    
    queue<BinaryTreeNode<int>*> q;
    vector<int> v1;
    vector<int> v2;
  
    q.push(root1);
    solve(root1, v1, q);

    q.push(root2);
    solve(root2, v2, q);
    
    return check(v1,v2);

    
}
