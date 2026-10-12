#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;
    
    public:
        Stack(){
            top = nullptr; //empty list
        }
        bool isEmpty(){
            return top == nullptr;
        }
        void push (int value){ //push function
            Node* newNode = new Node; //initialize node
            newNode->data = value; //put value to the node
            newNode->next = top; //put newnode as top
            
            top = newNode; //establish new node as the top
        }
        int pop(){
            if(isEmpty()){ //if statement if there's no values to operate or list is empty
                cout << "Stack Underflow\n";
                return -1;
            }
            Node* temp = top; // temporary pointer to the top node
            int value = top->data; //read value in the top
            top = top->next; //point to the next node
            delete temp; //removes memory inside the temp
            return value;
        }
        int peek(){
            if (isEmpty()){
                return -1;
            }
            return top->data;
        }

};
void convertToBase (int x, int y){  //fucntion to convert x to y
     if (x == 0) {
        cout << 0 << "\n";
        return;
    }
        
    Stack s;
        
    while (x > 0){
        int remainder = x % y;
        s.push(remainder);
        x /= y;
    }
    while (!s.isEmpty()){
        int value = s.pop();
        if (value >= 10){
            cout << 'a' + (value - 10);
        } else {
            cout << value;
        }
    }
    cout << "\n";
}

int main (){
    int x, y;
    while (cin >> x >> y){
        convertToBase(x, y);
    }
    
    return 0;
}
