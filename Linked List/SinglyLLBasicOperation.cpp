#include <iostream> // not wrokign properly for the commands
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* NodePtr;

void addHead (NodePtr& head, int newdata){
    NodePtr newPtr = new Node;
    
    newPtr->data = newdata;
    newPtr->next = head;
    head = newPtr;
}

void deleteHead (NodePtr& head){
    if (head != NULL){
        NodePtr p = head;
        head = head->next;
        delete p;
    }
}

void displayList(NodePtr head){
    NodePtr p = head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
 NodePtr head = NULL;
 char command; 
 int value;
 
 cout << "Command(i - insert, d - for delete): ";
 cin >> command;
 cout << "\n";
 
 while (command){
     if (command = 'i'){
        cout << "Enter your input: " << endl;
        cin >> value;
        addHead(head, value);
        cout << "List: ";
        displayList(head);
     }
     else if (command = 'd'){
        deleteHead(head);
        cout << "After deleting head: ";
        displayList(head); 
     }
     else {
         cout << "INVALID COMMAND";
     }
}
 
    return 0;
}
