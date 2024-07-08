class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to create a mapping from each node to its parent and to find the target node.
    Node* createMap(Node* root, int target, map<Node*, Node*> &nodeMap) {
        Node* res = nullptr;
        queue<Node*> q;
        q.push(root);
        nodeMap[root] = nullptr;  // Root has no parent
        
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if (front->data == target) {
                res = front;
            }
            
            if (front->left) {
                nodeMap[front->left] = front;
                q.push(front->left);
            }
            
            if (front->right) {
                nodeMap[front->right] = front;
                q.push(front->right);
            }
        }
        
        return res;
    }

    // Function to simulate the burning process and calculate the time to burn the entire tree.
    int burnTree(Node* root, map<Node*, Node*> &nodeMap) {
        map<Node*, bool> visited;
        bool flag = false;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            flag = false;
            
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                
                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                
                if (nodeMap[front] && !visited[nodeMap[front]]) {
                    flag = true;
                    q.push(nodeMap[front]);
                    visited[nodeMap[front]] = true;
                }
            }
            
            if (flag) ans++;
        }
        return ans;
    }

    // Main function to find the minimum time to burn the entire tree starting from the target node.
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeMap;
        Node* targetNode = createMap(root, target, nodeMap);
        int ans = burnTree(targetNode, nodeMap);
        return ans;
    }
};

