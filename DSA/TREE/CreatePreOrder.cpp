class Solution {
private:
    // Create a map from inorder values to their indices for quick lookup
  int findPosition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }

    // Recursive function to create the tree
    Node* create(int in[], int post[], int n, int &index, int inStart, int inEnd) {
        // Base case: if index exceeds bounds or inStart is greater than inEnd, return nullptr
        if (index <0 || inStart > inEnd) {
            return nullptr;
        }

        // Get the current root element from postorder array and move to the next index
        int element = post[index--];
        Node* root = new Node(element);

        // Find the position of the current element in the inorder array
        int position = findPosition(in, inStart, inEnd, element, n);

        // Recursively build the left and right subtrees
        root->right = create(in, post, n, index, position + 1, inEnd);
        root->left = create(in, post, n, index, inStart, position - 1);

        return root;
    }
  public:

    Node *buildTree(int n, int in[], int post[]) {
        
        int index = n-1;
        Node* ans = create(in, post, n, index, 0, n-1);
        return ans;
    }
};
