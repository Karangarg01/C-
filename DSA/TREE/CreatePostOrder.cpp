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
    Node* create(int in[], int pre[], int n, int &index, int inStart, int inEnd) {
        // Base case: if index exceeds bounds or inStart is greater than inEnd, return nullptr
        if (index >= n || inStart > inEnd) {
            return nullptr;
        }

        // Get the current root element from preorder array and move to the next index
        int element = pre[index++];
        Node* root = new Node(element);

        // Find the position of the current element in the inorder array
        int position = findPosition(in, inStart, inEnd, element, n);

        // Recursively build the left and right subtrees
        root->left = create(in, pre, n, index, inStart, position - 1);
        root->right = create(in, pre, n, index, position + 1, inEnd);

        return root;
    }

public:
    // Main function to build the tree
    Node* buildTree(int in[], int pre[], int n) {

        int index = 0;
        // Create the tree and return its root
        Node* ans = create(in, pre, n, index, 0, n - 1);

        return ans;
    }
};
