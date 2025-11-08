#include <iostream>
#include <vector>
using namespace std;

vector<int>spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row*col;
        //index initilization
    int startingrow = 0;
    int startingcol = 0;
    int endingrow = row-1;
    int endingcol = col-1;

    while(count<total){
            // starting row
        for(int i =startingcol;count<total && i<=endingcol;i++){
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

            //ending coloumn
        for(int i =startingrow;count<total && i<=endingrow;i++){
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

            //ending row
        for(int i=endingcol;count<total && i>=startingcol;i--){
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;

            //starting coloumn
        for(int i=endingrow;count<total && i>=startingrow;i--){
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }  
    return ans;      
}
int main() {
    int rows,cols;
    cout<<"enter number of rows and coloumns"<<endl;
    cin>>rows>>cols;
    
	vector<vector<int>>arr(rows,vector<int>(cols));
	
	cout<<"enter elements"<<endl;
	for(int i=0;i<rows;i++){
	    for(int j=0;j<cols;j++){
	        cin>>arr[i][j];
	    }
	}
	vector<int>result=spiralOrder(arr);
	
	cout<<"spiral Order vector"<<endl;
	for(int val:result){
	    cout<<val<<" ";
	}
	cout<<endl;
   
    return 0;
}