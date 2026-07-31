#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    int even = 0, odd = 0;
    
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0){ // operation to check if numbers are even, if certain iteration are met then it will be the counts on even and odd results
            even++;
        } else{
            odd++;
        }
    }
    cout << "Even number count: " << even << endl; 
    cout << "Odd number count: " << odd << endl;
    
    return 0;
}
