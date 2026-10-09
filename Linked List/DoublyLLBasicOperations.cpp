#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout << "EMPTY" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertBeginning(Node*& head, int value, int& nodeCount) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    nodeCount++;
}

void deleteValue(Node*& head, int value, int& nodeCount) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }
    //if statements to check prev and next nodes contains valkues
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    nodeCount--;
    cout << "[" << nodeCount << "] ";
    display(head);
}
// bool function to check if value exists or not in the list
bool search(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "VALUE FOUND" << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "VALUE NOT FOUND" << endl;
    return false;
}
//function to refresh or reset the list to empty
void refresh(Node*& head, int& nodeCount) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    nodeCount = 0;
    cout << "[0] EMPTY" << endl;
}

int main() {
    Node* head = NULL;
    int nodeCount = 0;

    //command instructions
    cout << "Commands: i for insert, s for search, d for delete, and r for refresh" << endl;

    char command;
    int value;
    while (cin >> command >> value) {
        // function calls
        if (command == 'i') {
            insertBeginning(head, value, nodeCount);
            cout << "[" << nodeCount << "] ";
            display(head);
        } else if (command == 'd') {
            deleteValue(head, value, nodeCount);
        } else if (command == 's') {
            search(head, value);
        } else if (command == 'r') {
            refresh(head, nodeCount);
        }
    }
    return 0;
}
