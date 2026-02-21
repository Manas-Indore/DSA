#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at Specific Position (1-based index)
    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            insertAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display List
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtStart(10);
    list.insertAtStart(5);
    list.insertAtEnd(20);
    list.insertAtPosition(15, 3);

    list.display();

    return 0;
}