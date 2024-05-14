/*
  Overall space complexity: O(N)
  Overall time complexity: O(N)
  */


private:
    void insAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        
        // Create a clone list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        
        Node* temp = head;
        
        while(temp){
            insAtTail(cloneHead, cloneTail,temp->data);
            temp = temp->next;
        }
        
        // Create a map
        unordered_map<Node*, Node*> oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode && cloneNode){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode){
           cloneNode->arb = oldToNew[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
            
        }
        
        return cloneHead;
        
    }
