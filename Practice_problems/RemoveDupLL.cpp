// Sorted Linked list
\Node * removeDuplicates(Node *head)
{
    if(head==nullptr) return nullptr;
    Node* temp = head;
    while(temp->next){
        if(temp->data == temp->next->data){
            Node* curr = temp->next;
            temp->next = curr->next;
            delete curr;
        }

        else temp=temp->next;
    }

    return head;
}



// Unsorted Linked list
Node* removeDuplicates(Node* head) {
    if (!head) return nullptr; // If the list is empty, return nullptr

    Node* temp = head;
    map<int, bool> visited; // Store values rather than nodes

    visited[temp->data] = true; // Mark first node value as visited

    while (temp->next) {
        if (visited[temp->next->data]) { // Check if the next node value is visited
            Node* curr = temp->next;
            temp->next = curr->next;
            delete curr;
        } else {
            visited[temp->next->data] = true; // Mark next node value as visited
            temp = temp->next; // Move to the next node
        }
    }

    return head;
}
