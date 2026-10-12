#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
    private:
        Node* top;
    
    public:
        Stack(){
            top = nullptr;
        }
        bool isEmpty(){
            return top == nullptr;
        }
        void push(int value){
            Node* newnode = new Node;
            newNode->data = value;
            newNode->next = top;
            
            top = newNode;
        }
        int pop(){
            if(isempty()){
                cout << "Stack underflow\n";
                retur -1;
            }
            Node* temp = top;
            int value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
        int peek(){
            if (isempty()){
                return -1;
            }
            return top->data;
        }
};

int main (){
    Stack s;
    
    
    return 0;
}
