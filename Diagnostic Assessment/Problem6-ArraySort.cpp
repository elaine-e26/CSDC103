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
    
    bool isSorted = true;
    cout << "Is array sorted? " ;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            isSorted = false;
            break;
        }
    }
    
    if (isSorted)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
