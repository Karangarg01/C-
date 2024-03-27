LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* curr;
    LinkedListNode<int>* prev = NULL;
    while(temp!=NULL){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
        
    }
    return prev;
}
