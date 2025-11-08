#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    // Create an array of pointers (to represent rows)
    int** arr = new int*[n];

    // Create an array to store the number of columns for each row
    int* m = new int[n];

    // Allocate space for each row
    for(int i = 0; i < n; i++){
        cout << "Enter the number of columns for row " << i+1 << ": ";
        cin >> m[i]; 
        arr[i] = new int[m[i]];  // Dynamically allocate columns for each row
    }

    // Input elements
    cout << "Enter the elements row-wise:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            cin >> arr[i][j];
        }
    }

    // Output elements
    cout << "The 2D array is:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing memory
    for(int i = 0; i < n; i++){
        delete[] arr[i];  // Delete each row
    }
    delete[] arr;  // Delete the array of row pointers
    delete[] m;    // Delete the array that holds column sizes

    return 0;
}