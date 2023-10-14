#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int data)
    {
        value = data;
        next = nullptr;
    }
};

class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = nullptr;
    }

    void insAtHead(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int value)
    {
        Node *n = new Node(value);
        if (head == NULL)
        {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void disp()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->"; // 1-> 2-> 2=> 3-> 3-> 3 -> null
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void remDup()
    {
        Node *curr = head;
        while (curr)
        {
            while (curr->next && curr->value == curr->next->value)
            {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                free(temp);
            }
            curr = curr->next;
        }
    }

    void reversePrint(Node *head)
    {

        if (head == nullptr)
        {
            return;
        }
        reversePrint(head->next);
        cout << head->value << " ";
    }

    Node *reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {

            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        Node *newHead = prev;
        return newHead;
    }

    Node *revRecursion(Node *&head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *new_head = revRecursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    Node *revK(Node *&head, int k)
    {
        Node *prev = nullptr;
        Node *curr = head;
        int counter = 0;

        while (curr != nullptr && counter < k)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            counter++;
        }
        if (curr != nullptr)
        {

            Node *new_head = revK(curr, k);
            head->next = new_head;
        }
        return prev;
    }
};

int getLen(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)

    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node*  move(Node* head, int k){
    Node* ptr = head;
    while (k--)
    {
        ptr = ptr->next;
    }
    return ptr; 
}
bool checkEqualLL(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value != ptr2->value)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return (ptr1 == NULL && ptr2 == NULL);
}

Node* getIntersection(Node* head1, Node* head2){
    int l1 = getLen(head1);
    int l2 = getLen(head2);

    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        int k = l1-l2;
        ptr1 = move(head1,k);
        ptr2 = head2;
    }

    else{
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = move(head2,k);
    }

    while (ptr1!=nullptr)
    {
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
        return NULL;

    
}
int main()
{
    Linkedlist l, l2;
    l.insertAtTail(2);
    l.insertAtTail(4);
    l.insertAtTail(6);
    l.insertAtTail(10);

    l2.insertAtTail(5);
    l2.insertAtTail(9);
    // l2.insertAtTail(6);
    l2.head->next->next = l.head->next->next->next;

    l.disp();
    l2.disp();

    // cout << checkEqualLL(l.head, l2.head);
    Node* intersect = getIntersection(l.head,l2.head);
    if(intersect){
        cout << intersect->value << endl;
    }
    else return -1;
    return 0;
}