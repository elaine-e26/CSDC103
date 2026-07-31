#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elemnts: ";
    cin >> n; 
    
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bool isSorted = true; //function declarationfor sorted result
    cout << "Is array sorted? " ;
    for (int i = 1; i < n; i++) { //iteration of the array
        if (arr[i] < arr[i - 1]) { //comparison of the arrays on which of the two are higher 
            isSorted = false; //fubnction declaration, if decision is met, then it will break resulting to false
            break;
        }
    }
    
    if (isSorted)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
