Node* slowPointer(Node* head){

    if(head==NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast){
        fast = fast->next;

        if(fast) fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

Node* len(Node* head){

    int count = 1;
    Node* temp = head;

    while(temp->next){
        temp = temp->next;
        count++;
    }

    if(count==1 || count==0) return head;
    
    temp = head;
    int mid = count/2;
    int i=1;
    while(i<mid){
        temp = temp->next;
        i++;
    }

    return temp->next;
}

Node *findMiddle(Node *head) {
    // Write your code here

    return slowPointer(head);
}
