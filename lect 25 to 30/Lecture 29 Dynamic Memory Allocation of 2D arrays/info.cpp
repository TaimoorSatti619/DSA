#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter number of rows : ";
    cin>>row;
    int col;
    cout<<"Enter the number of columns : ";
    cin>>col;

    /*
    // creating dynamic array for row=col
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int** array = new in* [n]; 
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    */
   
    // creating dynamic array for row * col
    int** arr = new int* [row]; 
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // take input
    cout<<"Enter 2D Array Elements : ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    // print array
    cout<<"Your Array is "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Release Heap
    for(int i=0; i<row; i++){
        delete [] arr[i];
    }
    delete []arr;
    return 0;
}