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
        next = NULL;
    }
};

class LL
{
    Node *head;

public:
    LL()
    {
        head = NULL;
    }

    void insAtHead(Node*head , int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }

    void sort(Node* head){
        Node* i;
        Node* j;
        for ( i = head; i->next!=nullptr; i=i->next)
        {
            for ( j = i->next; j!= nullptr; j = j->next)
            {
                if(i->value > j->value){
                    swap(i->value,j->value);
                }
            }
            
        }
        
    }
    Node* add(Node* head1, Node* head2){
        Node* newNode = head1;
        Node* temp = head1->next;
        while(temp!=nullptr){
            newNode->next = temp;
            temp = temp->next;
        }

        while (head2!=NULL)
        {
            newNode->next = head;
            head = head->next;
        }
        
        return newNode;
    }
    void disp(Node* head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LL l;
    Node* h1;
    l.insAtHead(h1,3);
    l.insAtHead(h1,2);
    l.insAtHead(h1,4);
    l.insAtHead(h1,1);
    // Node* newH = l.add();
    l.disp(h1);

    return 0;
}