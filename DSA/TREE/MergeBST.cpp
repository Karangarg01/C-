/*
Approach 1: Using vector
  Perform inorder traversal of both BSTs to get two sorted arrays.
  Merge the two sorted arrays.
  Convert the merged sorted array back to a balanced BST using the inorderToBST function.
  
  Time Complexity: O(n1 + n2)
  Space Complexity: O(n1 + n2)


  Approach 2: Using Doubly Linked List
    Convert both BSTs to doubly linked lists.
  Merge the two sorted doubly linked lists.
  Convert the merged doubly linked list back to a balanced BST 

  Overall time complexity: O(n1 + n2)
  Overall space complexity: O(h1 + h2)
*/

void inorder(TreeNode* root, vector<int> &in){
    if(root==nullptr) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArr(vector<int> a, vector<int> b){
    vector<int> ans;

    int i=0, j=0;
    
    while(i<a.size() && j<b.size()){
        if(a[i] <= b[j])
            ans.push_back(a[i++]);

        else    
            ans.push_back(b[j++]);
    }

    while(i<a.size()) ans.push_back(a[i++]);

    while(j<b.size()) ans.push_back(b[j++]);

    return ans;
}

TreeNode* inorderToBST(vector<int> v, int s, int e){

    if(s>e) return nullptr;

    int mid = s+(e-s)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = inorderToBST(v, s, mid-1);
    root->right = inorderToBST(v, mid+1, e);

    return root;    
}

void BSTToDoublyLL(TreeNode* root, TreeNode* &head){

    if(root==nullptr) return;

    BSTToDoublyLL(root->right, head);

    root->right = head;
    if(head) head->left = root;

    head = root;

    BSTToDoublyLL(root->left, head);
}

TreeNode* mergeLL(TreeNode* head1, TreeNode* head2){

    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    while(head1 && head2){
        if(head1->data <= head2->data){
            if(head==nullptr){
                head = head1;
                tail = head1;
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1=head1->right;
        }
        else{
            if(head==nullptr){
                head = head2;
                tail = head2;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2=head2->right;           
        }
    }

    while(head1){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1=head1->right;
    }

    while(head2){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2=head2->right;
    }

    return head;
}

// Count the number of nodes in the Doubly Linked List
int countNodes(TreeNode* head) {
    int count = 0;
    TreeNode* temp = head;
    while(temp) {
        count++;
        temp = temp->right;
    }
    return count;
}

// Convert Sorted Doubly Linked List to Balanced BST
TreeNode* sortedListToBST(TreeNode* &head, int n) {
    if(n <= 0) return nullptr;

    TreeNode* left = sortedListToBST(head, n / 2);
    TreeNode* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedListToBST(head, n - n / 2 - 1);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // vector<int> tree1;
    // vector<int> tree2;

    // inorder(root1, tree1);
    // inorder(root2, tree2);

    // return mergeArr(tree1, tree2);

    TreeNode* head1 = nullptr;
    TreeNode* head2 = nullptr;

    BSTToDoublyLL(root1, head1);
    head1->left = nullptr;
    BSTToDoublyLL(root2, head2);
    head2->left = nullptr;

    TreeNode* temp = mergeLL(head1, head2);

    vector<int> ans;

    while(temp){
        ans.push_back(temp->data);
        temp = temp->right;
    }
    
    return ans;
}
