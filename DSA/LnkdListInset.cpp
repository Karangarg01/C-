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

class Linkedlist
{
public:
    Node *head;
    Linkedlist(){
        head = NULL;
    }

    void insertHead(int value)
    {
        Node *new_next = new Node(value);
        new_next->next = head;
        head = new_next;
    }

    void insertPos(int pos, int data)
    {
        Node *n = new Node(data);
        Node *temp = head;
        int currPos = 0;
        while (currPos != pos - 1)
        {
            temp = temp->next;
            currPos++;
        }
        n->next = temp->next;
        temp->next = n;
    }
    
    void delHead()
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    void disp()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void delPosTail()
    {
        Node *secondLast = head;
        while (secondLast->next->next != NULL)
        {
            secondLast = secondLast->next;
        }
        // temp->next = temp->next->next;
        Node *temp = secondLast->next;
        free(temp->next);
        secondLast->next = NULL;
    }
};

void delPos(Node *&head, int pos)
{
    Node *secondLast = head;
    int curr = 0;
    while (curr != pos - 1)
    {
        secondLast = secondLast->next;
        curr++;
    }
    Node *temp = secondLast->next;
    secondLast->next = secondLast->next->next;
    free(temp);
}

void delAlter(Node *&head)
{
    Node *n = head;
    while (n != NULL && n->next != NULL)
    {
        Node *fr = n->next;
        n->next = n->next->next;
        free(fr);
        n = n->next;
    }
}
int main()
{
    Linkedlist l1;
    l1.insertHead(1);
    l1.insertHead(50);
    l1.insertPos(2, 10);
    l1.insertHead(77);
    l1.insertHead(99);
    l1.disp();
    delAlter(l1.head);
    l1.disp();
    return 0;
}