#include<iostream>
using namespace std;
int main(){
    // no of rows
    int row;
    cout<<"Enter number of rows : ";
    cin>>row;

    // column size 
    int c1;
    cout<<"Enter size of column for row 1 : ";
    cin>>c1;

    int c2;
    cout<<"Enter size of column for row 2 : ";
    cin>>c2;

    int c3;
    cout<<"Enter size of column for row 3 : ";
    cin>>c3;

    // allocate rows
    int** JaggedArray = new int*[row];

    // alocate memory for columns in each row

    JaggedArray[0] = new int[c1];
    JaggedArray[1] = new int[c2];
    JaggedArray[2] = new int[c3];

    // Input Jagged array
    cout<<"Enter element for JaggedArray : ";
    for(int i=0; i<row; i++){
        int col = (i == 0) ? c1 : (i == 1) ? c2 : c3;
        for(int j=0; j<col; j++){
            cin>>JaggedArray[i][j];
        }
    }

    // Output Jagged array
    cout<<"Your JaggedArray is "<<endl;
    for(int i=0; i<row; i++){
        int col = (i == 0) ? c1 : (i == 1) ? c2 : c3;
        for(int j=0; j<col; j++){
            cout<<JaggedArray[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}