#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* prev;
    Node* next;
    Node(int data){
        value = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLL{
    public:

    Node* head;
    Node* tail; 
    DoublyLL(){
        head = NULL;
        tail = NULL;
    }

    void display(){
        Node* temp = head;
        while (temp!=NULL)
        {
            cout << temp->value << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        
    }
    void insAthead(int data){
        Node* n = new Node(data);
        if (head==NULL)
        {
            head = n;
            tail = n;
            return;
        }
        
        n->next = head;
        n->prev = NULL;
        head->prev = n;
        head = n;
    }

    void insAttail(int data){
        Node* n = new Node(data);
        if(tail==NULL){
            head == n;
            tail == n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
        return;
    }


};
int main(){
    DoublyLL d;
    d.insAthead(1);


    d.insAthead(5);
    
    d.insAthead(3);
    d.display();
    return 0;
}