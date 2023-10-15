#include <iostream>
using namespace std;

class Stack{
    int capacity;
    int* arr;
    int top;
    public:
    Stack(int size){
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        if(top == capacity-1){
            cout << "Stack Full" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop(){
        if(top == -1){
            cout << "Underflow" << endl;
            return INT8_MIN;
        }

        top--;
    }

    int gettop(){
        if(top==-1){
            cout << "Underflow" << endl;
            return INT8_MIN;
        }

        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity-1 ;
    }

    int size(){
            return top+1;
    }
};
int main(){
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