#include <iostream>
#include <set>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end
    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to sort the linked list in ascending order
    void sortList() {
        std::set<int> elements;
        Node* current = head;
        while (current != nullptr) {
            elements.insert(current->data);
            current = current->next;
        }
        clearList();
        for (int element : elements) {
            insertNode(element);
        }
    }

    // Function to clear the linked list
    void clearList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Function to merge two sorted linked lists into one, keeping distinct elements
LinkedList mergeLists(const LinkedList& list1, const LinkedList& list2) {
    LinkedList mergedList;
    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            mergedList.insertNode(current1->data);
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            mergedList.insertNode(current2->data);
            current2 = current2->next;
        } else {
            mergedList.insertNode(current1->data);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != nullptr) {
        mergedList.insertNode(current1->data);
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        mergedList.insertNode(current2->data);
        current2 = current2->next;
    }

    return mergedList;
}

int main() {
    LinkedList list1, list2;
    int n, m;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        list1.insertNode(value);
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int value;
        std::cin >> value;
        list2.insertNode(value);
    }

  list1.sortList();
    list2.sortList();

    LinkedList mergedList = mergeLists(list1, list2);

      std::cout << "first:" ;list1.displayList();
    std:: cout << "second";list2.displayList();
    mergedList.displayList();

    return 0;
}
