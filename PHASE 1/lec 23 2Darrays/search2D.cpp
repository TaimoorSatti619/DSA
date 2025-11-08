#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int rowindex = 0;
    int colindex = col-1;

    while(rowindex < row && colindex >= 0){
        int element = matrix[rowindex][colindex];
        if(element == target){
            return 1;
        }
        if(element < target){
            rowindex++;
        }
        else{
            colindex--;
        }
    }
    return 0;       
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
    
    int key;
    cout<<"enter a number to search for"<<endl;
    cin>>key;
    
    if(searchMatrix(arr,key)){
        cout<<"element is present"<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }


    return 0;
}