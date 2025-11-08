#include <iostream>
#include <vector>
#include <string>
using namespace std;
//         <-vector int->

/*void solve(vector<int>nums,vector<vector<int>>&ans,int index){
    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}

vector<vector<int>>permute(vector<int>&nums){
    vector<vector<int>>ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;
}

int main(){
    vector<int>nums = {1,2,3};

    cout<<"original vector is "<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }cout<<endl;

    cout<<"permutations are "<<endl;
    vector<vector<int>>ans = permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;    
}*/

//     <-for strings->

void solve(string str,vector<string>&ans,int index){
    //base case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }
    for(int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,ans,index+1);
        //backtrack
        swap(str[index],str[i]);
    }
}

vector<string>generatepermutation(string &str){
    vector<string>ans;
    int index = 0;
    solve(str,ans,index);
    return ans;
}

int main() {
    string str="tuv";
    cout<<"string is"<<endl;
    cout<<str<<endl;
    cout<<"permutations of a string are"<<endl;
    vector<string>ans = generatepermutation(str);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}