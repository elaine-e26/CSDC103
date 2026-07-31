#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of element: ";
    cin >> n; 
    
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { // iteration of the array elements
        cin >> arr[i];
    }
    
    cout << "Reversed: ";
    for (int i = n - 1; i >= 0; i--) { //used operation - to indicate going back or reversal
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
