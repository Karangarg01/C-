#include <iostream>
using namespace std;

template <typename t>
class Node
{
public:
    t value;
    Node *next;

    Node(t data)
    {
        value = data;
        next = nullptr;
    }
};
int main()
{
    Node<int> *n1 = new Node<int>(5);
    cout << n1->value << endl;

    Node<char> *n2 = new Node<char>('a');
    cout << n2->value << endl;
    return 0;
}