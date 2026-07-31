#include <iostream>
using namespace std;

bool isEven(int n) {     //declaration of the function isEven thru boolean for true/false (even/odd) answers
    return (n % 2 == 0);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;  //entry of number
    
    if (isEven(n)) //function call to check if the number is even or odd
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
    
    return 0;
}
