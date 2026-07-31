#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;  
    
    int smallest = a;   //assume a is the smallest number
    
    if (b < smallest) // comparison of first and second number, if result is less than, then it will be the new smallest number
        smallest = b;
    if (c < smallest) //comparison of the new smallest number from the previous comparison to the 3rd number, result then will be the smallest numebr of all
        smallest = c;
    
    cout << "Smallest number: " << smallest << endl;
    
    return 0;
}
