#include <iostream>
#include <vector>
#include <string>
using namespace std;

 //      <-SUBSETS->

/*void solve(vector<int>arr,vector<int>output,int index,vector<vector<int>>&ans){
    //base case
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(arr,output,index+1,ans);
    //include
    int element = arr[index];
    output.push_back(element);
    solve(arr,output,index+1,ans);
}

vector<vector<int>>subsets(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>output;
    int index = 0;
    solve(arr,output,index,ans);
    return ans;
}

int main(){
    vector<int>arr ={1,2,3};
    cout<<"original array is"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"subsets are"<<endl;
    vector<vector<int>>ans = subsets(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}*/


 //      <-SUBSEQUENCES->

void solve(string str,string output,int index,vector<string> &ans){
    //base case
    if(index >= str.size()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    //exclude
    solve(str,output,index+1,ans);
    //include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}

vector<string>subsequences(string str){
    vector<string>ans;
    string output = " ";
    int index = 0;
    solve(str,output,index,ans);
    return ans;
}

int main(){
    string str = "abc";
    cout<<"original array is"<<endl;
    cout<<str<<endl;
    cout<<"subsequences are"<<endl;
    vector<string>ans = subsequences(str);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}