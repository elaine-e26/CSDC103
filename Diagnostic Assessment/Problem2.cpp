#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 0; i < n; i++) { 
        if (arr[i] < min) min = arr[i]; 
        if (arr[i] > max) max = arr[i];
    }
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    return 0;
}
