#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insert(Node *&head, int value)
{
    Node *new_next = new Node(value);
    new_next->next = head;
    head = new_next;
}

void insertAtTail(Node* &head, int value){
    Node* n = new Node(value);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
bool search(Node* head, int key){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->val==key){
            return true;
        }
        temp = temp->next;
    }
    return false;

}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // Node *n1 = new Node(32);
    // cout  << n1->val << endl << n1 ->next;
    Node *n1 = NULL;
    cout << "Inserting at front" << endl;
    insert(n1, 33);
    // insert(n1, 77);
    insert(n1, 54);
    // display(n1);

    cout << "Inserting at tail" << endl;
    insertAtTail(n1,199);
    // insertAtTail(n1,11);
    insertAtTail(n1,142);
    display(n1);
    cout << search(n1,199);

    return 0;
}