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

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enque(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {             // Queue is empty
            head = n; // Both head and tail are given value of n
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
        size++; // increase size with each enque
    }
    void dequeue()
    {
        if (head == NULL)
        {
            return; // Queue is empty
        }

        Node *oldHead = head;
        Node *newHead = head->next;
        head = newHead;
        if (head == NULL)
            tail = nullptr;
        free(oldHead);
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
            return (head == NULL);
    }

    int front(){
        if(head == NULL) return -1;
        return head->value;
    }

};
int main()
{
    Queue q;
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.dequeue();
    q.enque(50);

    while(not q.isEmpty()){
        cout << q.front() << " ";
        q.dequeue();
    }
    return 0;
}