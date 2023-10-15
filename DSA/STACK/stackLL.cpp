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

class Stack
{
    int capacity;
    int currSize;
    Node *head;

public:
    Stack(int c)
    {
        capacity = c;
        currSize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isFull()
    {
        return currSize == capacity;
    }

    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }

        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            return;
        }

        n->next = head;
        head = n;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Underflow" << endl;
            return INT8_MIN;
        }
        Node *n = head->next;
        Node *remNode = head;
        int result = remNode->value;
        delete remNode;
        head = n;
        return result;
    }

    int size(){
        return currSize;
    }
    int gettop()
    {
        if (head == NULL)
        {
            cout << "Underflow" << endl;
            return INT8_MIN;
        }
        return head->value;
    }
};
int main()
{
    Stack st(5);
    st.push(1);
    st.push(5);
    st.push(25);
    cout << st.gettop() << endl;
    st.push(64);
    st.push(32);
    cout << st.gettop() << endl;
    st.push(3);
    return 0;
}