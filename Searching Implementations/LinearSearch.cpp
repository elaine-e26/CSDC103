#include <iostream>
using namespace std;

int linearSearch (int arr[], int size, int target){ //parameters
    for (int i=0; i < size; i++){ //for loop used to simplify search, function to check whether the current index is not or before the last index 
        if (arr[i] == target){ //to check if the current index is the target
            return i; //will return the index if the target is reached
        }
    }
    return -1; //will not return index if target is not found
}

int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int size = 5;
  int target;
  
  cout << "Enter the number to search: "; 
  cin >> target;
  
  int result = linearSearch(arr, size, target); //function call to start traversal
  
  //conditions to check if target is found or not
  if(result != -1){
      cout << "Element found at index: " << result << endl;
  }else{
      cout << "Element not found!" << endl;
  }

    return 0;
}
