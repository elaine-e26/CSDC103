#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter elements: ";
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    cout << "Sum of elements: " << sum << endl;
    return 0;
}
