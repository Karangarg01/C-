/* 
  In this algorithm the concept of slow and fast pointer is used to find Loop in a Linked List
  Time complexity = O(n)
*/

#include <iostream>
#include <map>
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

public:
    Node *head;
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

    Node* tail(){
        Node* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        return temp;
    }
    
    
    bool FloydsAlgo(){
        if(head==NULL){
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast){
            
            fast = head->next;
            
            if(fast!=NULL) fast = head->next;
            
            slow = head->next;
            
            if(fast==slow){
                cout << "Loop at element " << fast->value << endl;
                return true;
            }
            
        }
        return false;
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
    Node* n;

    l.insAtHead(1);
    l.insAtHead(2);
    l.insAtHead(3);
    l.insAtHead(4);
    
    n = l.tail();
    n->next = l.head->next;
    
    if(l.FloydsAlgo()) cout << "Loop is present" << endl;
    else cout << "No loop" << endl;
    return 0;
}
