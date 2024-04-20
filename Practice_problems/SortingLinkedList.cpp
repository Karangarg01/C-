// Sorting by replacing the values of original linked list
Node* sortList(Node *head){
    Node* temp = head;
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    while(temp!=nullptr){
        if(temp->data == 0) zeroCount++;
        else if(temp->data ==1 ) oneCount++;
        else if(temp->data == 2) twoCount++;

        temp = temp->next;
    }
    
    temp = head;
    while(temp!=nullptr){
        if(zeroCount!=0){
            temp->data = 0;
            zeroCount--;
        }

        else if(oneCount!=0){
            temp->data = 1;
            oneCount--;
        }

        else if(twoCount!=0){
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }

    return head;
}




// Sorting the linked list without replacement of data by rearranging the pointers 

void insAtTail(Node* &tail, int data){
        Node* n = new Node(data);
        tail->next = n;
        tail = n;
}
Node* sortList(Node *head){

    // Creating dummy nodes 
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;

    // Creating separate linked list for 0, 1, 2
    while(temp){
        if(temp->data == 0) insAtTail(zeroTail,0);
        else if(temp->data == 1) insAtTail(oneTail, 1);
        else if(temp->data == 2) insAtTail(twoTail, 2);

        temp = temp ->next;
    }

    // Merging linked list of 0s, 1s and 2s
    if(oneHead->next != nullptr) zeroTail ->next = oneHead->next;           // Check if 1s list is present
    else zeroTail->next = twoHead->next;                // If 1s list is not present

    oneTail->next = twoHead->next;
    twoTail -> next = nullptr;

    head = zeroHead->next;              // Assigning the head to its correct position
    delete oneHead;
    delete zeroHead;
    delete twoHead;

    return head;
}
