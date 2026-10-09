#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// function declarations
void insertBeginning(Node*& head, int value);
void deleteValue(Node*& head, int value);
bool search(Node* head, int value);
void display(Node* head);
void refresh(Node*& head);
int countNodes(Node* head);

void insertBeginning(Node*& head, int value) { //insert head or first node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void deleteValue(Node*& head, int value) { //function to delete values 
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "VALUE NOT FOUND" << endl; //if list is empty
        return;
    }
  // to check previous and next nodes if empty
    if (temp->prev != NULL) { 
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "[" << countNodes(head) << "] ";
    display(head);
}

// bool function to check if values exists or not in the list
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
// function to make the lkist empty again
void refresh(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    cout << "[0] EMPTY" << endl;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;

    // commands
    cout << "Commands: i for insert, s for search, d for delete, and r for refresh" << endl;

    char command;
    int value;
    while (cin >> command >> value) {
        if (command == 'i') {
            insertBeginning(head, value); //function calls
            cout << "[" << countNodes(head) << "] ";
            display(head);
        } else if (command == 'd') {
            deleteValue(head, value);
        } else if (command == 's') {
            search(head, value);
        } else if (command == 'r') {
            refresh(head);
        }
    }
    return 0;
}
