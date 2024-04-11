/* Naive Approach to find Loop/cycle detection in a Linked List using map
   Space Complexity = O(n)
   Time Complexity  = O(n)
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
    
    bool LoopCheck(){
        if(head==NULL){
            return false;

        }
        map<Node*, bool> visited;
        Node* temp = head;
        
        while(temp){
            
            if(visited[temp]==true){
                cout << "Loop at element " << temp->value << endl;
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
            
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
    
    if(l.LoopCheck()) cout << "Loop is present" << endl;
    else cout << "No loop" << endl;
    return 0;
}
