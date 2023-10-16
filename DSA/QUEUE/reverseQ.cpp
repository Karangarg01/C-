#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    queue<int> input;
    stack<int> temp;
    input.push(10);
    input.push(20);
    input.push(30);
    input.push(40);
    input.push(50);

    while (not input.empty())
    {
        temp.push(input.front());
        input.pop();
    }

    while (not temp.empty())
    {
        input.push(temp.top());
        temp.pop();
    }
    

    while (not input.empty())
    {
        cout << input.front() << endl;
        input.pop();
    }
    
    return 0;
}