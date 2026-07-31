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
    
    int min = arr[0]; //declaration for setting the value of min/max to zero
    int max = arr[0];
    
    for (int i = 0; i < n; i++) { //each iteration will comparing less than or greater to determine the minimum and maximum value for each
        if (arr[i] < min) min = arr[i]; 
        if (arr[i] > max) max = arr[i];
    }
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    return 0;
}
