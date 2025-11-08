#include <iostream>
#include <vector>
using namespace std;
 
vector<int>waveprint(vector<vector<int>>arr,int nrows,int mcols){
    vector<int>ans;
    for(int j=0;j<mcols;j++){
        if(j&1){
            // odd -> bottom se oper
            for(int i=nrows-1;i>=0;i--){
                ans.push_back(arr[i][j]);
            }
        }
        else{ //even -> oper sey neechey
            for(int i=0;i<nrows;i++){
                ans.push_back(arr[i][j]);
            }
     }
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
	vector<int>result=waveprint(arr,rows,cols);
	
	cout<<"wave print vector"<<endl;
	for(int val:result){
	    cout<<val<<" ";
	}
	cout<<endl;
   
    return 0;
}