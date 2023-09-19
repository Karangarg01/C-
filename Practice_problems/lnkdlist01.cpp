#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int data)
    {
        next = NULL;
    }
};

void insAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->value = val;
    n->next = head;
    head = n;
    cout << "Node inserted" << endl;
}
void disp(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *n = NULL;
    int val, choice;
    do
    {
        cin >> val;
        insAtHead(n,val);
        cin >> choice;
    } while (choice==0);
    
    cout << "Linked List: ";
    disp(n);
    cout << "\nNode ended" << endl;
    return 0;
}