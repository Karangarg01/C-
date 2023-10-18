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

    void insAtHead(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }

    void rearrange()
    {
        if (head == NULL || head->next == nullptr)
        {
            return;
        }

        Node *oddHead = nullptr;
        Node *oddTail = nullptr;
        Node *evenHead = nullptr;
        Node *evenTail = nullptr;

        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->value % 2 == 0)
            {
                if (evenHead == nullptr)
                {
                    evenHead = curr;
                    evenTail = curr;
                }
                else
                {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            else
            {
                if (oddHead == nullptr)
                {
                    oddHead = curr;
                    oddTail = curr;
                }
                else
                {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            curr = curr->next;
        }

        if (evenTail != nullptr)
        {
            evenTail->next = oddHead;
        }
        if (oddTail != nullptr)
        {
            oddTail->next = nullptr;
        }
        head = evenHead;
    }
    void disp()
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
    l.insAtHead(1);
    l.insAtHead(2);
    l.insAtHead(3);
    l.insAtHead(4);
    l.disp();
    l.rearrange();
    l.disp();
    return 0;
}