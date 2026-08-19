#include <iostream>
using namespace std;

int matrixA[1000][1000];
int matrixB[1000][1000];
int sumMatrix[1000][1000]; //initialized outside of main for it to be accessible anywhere in the program and to handle large array

int main() {
  int r, c;
  cin >> r >> c; //user input of rows and columns

  for (int i = 0; i < r; i++) { //will read and perform operation for each row
    for (int j = 0; j < c; j++) { //first column elements will be in MatrixA
      cin >> matrixA[i][j];
    }
    for (int j = 0; j < c; j++) { //next column elements will be in MatrixB
      cin >> matrixB[i][j];
    }
  }

  for (int i = 0; i < r; i++) { //addition of the matrices
    for (int j = 0; j < c; j++) {
      sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
      cout << sumMatrix[i][j]; //printing of the sum of MatrixA and MatrixB

      if (j < c - 1) {
        cout << " "; //space to separate element results
      }
    }
    cout << endl; //will read the next row iteration 
  }
    
return 0; //termination once all rows are read and operations performed
}
