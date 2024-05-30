node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

    }

    return slow;
}

node* merge(node* left, node* right){
    if(left==nullptr) return right;

    if(right==nullptr) return left;

    node* ans = new node(-1);

    node* temp = ans;
    while(left && right){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }

        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left){
            temp->next = left;
            temp = left;
            left = left->next;        
    }

    while(right){
            temp->next = right;
            temp = right;
            right = right->next;                
    }

    return ans->next;
}
node* mergeSort(node *head) {
    
    if(head==nullptr || head->next == nullptr){
        return head;
    }

    node* mid  = findMid(head);
    node* left = head;
    node* right = mid->next;

    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);

    return result;
}
