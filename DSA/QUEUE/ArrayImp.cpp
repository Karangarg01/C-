#include <bits/stdc++.h> 
class Queue {

private: 
    int size;
    int* arr;
    int qFront;
    int rear;
public:
    Queue() {
        size = 10000;
        arr = new int[size];
        qFront = 0, rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(rear == qFront) return true;
        else return false;
    }

    void enqueue(int data) {
        if(rear == size) return;

        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qFront == rear) return -1;
        
        int x = arr[qFront];
        arr[qFront] = -1;
        qFront++;
        if(qFront == rear){
            qFront = 0;
            rear = 0;
        }
        return x;

    }

    int front() {
        if(rear==qFront) return -1;
        return arr[qFront];
    }
};
