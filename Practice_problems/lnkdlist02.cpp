#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    string str;
    Node(int data)
    {
        value = data;
        next = NULL;
    }
    Node(string data)
    {
        str = data;
        next = nullptr;
    }
};

class LL
{
public:
    Node *head;
    LL()
    {
        head = nullptr;
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

    void insAtTail(int val)
    {

        Node *n = new Node(val);

        if (head == nullptr)
        {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void insAtpos(int val)
    {
        int pos;
        Node *temp = head;
        Node *curr = new Node(val);
        Node *n2;
        while (temp->next != nullptr)
        {
            if (temp->value < val && temp->next->value > val)
            {
                n2 = temp->next;
                temp->next = curr;
                curr->next = n2;
            }
            temp = temp->next;
        }
    }
    void insPos(int val)
    {
        Node *temp = head;
        Node *curr;
        Node *n = new Node(val);
        while (temp)
        {
            if (temp->value < val && temp->next->value > val)
                break;
            temp = temp->next;
        }
        curr = temp->next;
        temp->next = n;
        n->next = curr;
    }

    void insString(string val)
    {
        Node *n = new Node(val);
        if (head == nullptr)
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
    int sumNode(int k)
    {
        Node *temp = head;
        int counter = 0, sum = 0;
        while (counter != k)
        {
            temp = temp->next;
            counter++;
        }
        while (temp != nullptr)
        {
            sum +=  temp->value;
            temp = temp->next;
        }
        return sum;
    }
    void oddLL(){
        Node* temp = head;
        while (temp->next->value % 2 != 0)
        {
            temp = temp->next;
        }
        Node* curr = temp;
        if(head->value<curr->value){
            curr->next = head;
        }
        
    }
};

int main()
{
    LL l1;
    int t;
    int value, k;
    cin >> t;
    do
    {
        cin >> value;
        l1.insAtTail(value);
        t--;
    } while (t > 0);
    cin >> k;

    // l1.disp();
    cout << l1.sumNode(k);

    return 0;
}
