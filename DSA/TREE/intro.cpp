#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int data){
        value = data;
        left = NULL;
        right = NULL;
    }
};

Node* create(Node* root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = create(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = create(root->right);
    return root;
}
int main(){
    Node* root = NULL;
    root = create(root);
    return 0;
}