#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* NodePtr;


void insertNode(NodePtr& Rear, int item){ //insertion function for a sorted cll
    
    NodePtr New, Cur, Prev;
    
    New = new Node; //new node creaion
    New->data = item;
    
    if (Rear == NULL){ //current empty list
        Rear = New;
        New->next = New;
        return;
    }
    
    Prev = Rear; //reading from the first node
    Cur = Rear->next;
    
    do{ //finding the correct position, to examine the current node
        if (item <= Cur->data)
        break;
        Prev = Cur;
        Cur = Cur->next;
    }while (Cur != Rear->next); 
    
    New->next = Cur; //insertion of new node, logic behind cll
    Prev->next = New;
    
    if (item > Rear->data){ //updates the rear, checking if new item is larger than the rear as cll is already sorted
        Rear = New;
    }
}

void deleteNode(NodePtr& Rear, int item){ //deletion function
    
    NodePtr Cur, Prev;
    
    if (Rear == NULL){ //if rear is empty
        cout << "Trying to delete empty list" << endl;
        return;
    }
    
    Prev = Rear; //search or reading from the first node
    Cur = Rear->next;
    
    do { //finding of the node
        if (item <= Cur->data)
        break;
        
        Prev = Cur;
        Cur = Cur->next;
        
    } while (Cur != Rear->next);
    
    if (Cur->data != item){ //if item not found or not existing in the list
        cout << "Data Not Found" << endl;
        return;
    }
    
    if (Cur == Prev){ //special case if there's only one node in the list as cur and prev will point to the same node
        Rear = NULL;
        delete Cur;
        return;
    }
    
    if (Cur == Rear) //if deleting rear node, rear will be moved backwards
    Rear = Prev;
    
    Prev->next = Cur->next; //remove current
    
    delete Cur;
}


void print(NodePtr Rear){ //print function for displaying list after operations are done
    if (Rear == NULL){
        cout << "List is empty" << endl;
        return;
    }
    
    NodePtr Cur = Rear->next;
    
    do {
        cout << Cur->data << " ";
        Cur = Cur->next;
    } while (Cur != Rear->next);
    
    cout << endl;
}

int main() {
    
    NodePtr Rear = NULL; 
    
    insertNode(Rear, 5); //insertion function call
    insertNode(Rear, 17);
    insertNode(Rear, 68);
    insertNode(Rear, 43);
    insertNode(Rear, 35);
    insertNode(Rear, 87);
    
    cout << "List: ";
    print(Rear); //print function call
    
    deleteNode(Rear, 17); //deletion function call
    deleteNode(Rear, 68);
    deleteNode(Rear, 43);
    
    cout << "After deletion: ";
    print(Rear);
    
    insertNode(Rear, 3);
    insertNode(Rear, 9);
    
    cout << "After insertion: ";
    print(Rear);
    
    return 0;
}
