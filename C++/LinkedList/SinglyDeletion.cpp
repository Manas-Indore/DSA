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

    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL || pos <= 0) {
            cout << "Invalid operation\n";
            return;
        }

        if (pos == 1) {
            deleteAtStart();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
};