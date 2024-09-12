#include<map>
#include<queue>
vector<int> bottomView(TreeNode<int>* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    
    map<int ,int> mapping;
    queue<pair<TreeNode<int>*, int>> q;

    q.push(make_pair(root,0));
    
    while(!q.empty()){
       int size = q.size();

       for(int i=0; i<size; i++){
           
           pair<TreeNode<int>*, int> temp = q.front();
           q.pop();

           TreeNode<int>* frontNode = temp.first;
           int hd = temp.second;

            mapping[hd] = frontNode->data;


           if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));

           if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
       }

    }

    for(auto i:mapping){
        ans.push_back(i.second);
    }

    return ans;
}
