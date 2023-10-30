#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->value = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->value){
        root->right = insertIntoBST(root->right,d);
    }

    else{
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

void takeINput(Node* root){
    int data;
    cin >> data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->value << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}
int main(){
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeINput(root);
    cout << "Printting the BST" << endl;
    levelOrderTraversal(root);
    
}