#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        //transpose
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
        //reverse
    for(int i =0;i<matrix.size();i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
int main() {
    int rows,cols;
    cout<<"enter rows and coloumns"<<endl;
    cin>>rows>>cols;
    
    vector<vector<int>>arr(rows,vector<int>(cols));
    
    cout<<"enter elements"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    rotate(arr);
    
    cout<<"rotated matrix is"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}