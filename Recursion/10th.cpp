#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>>&m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>>&m,int n,vector<string>&ans,int x,int y,vector<vector<int>> visited,string path){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    //4 choices  D,L,R,U

    //DOWN
    int newx = x+1;
    int newy = y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //LEFT
    newx = x;
    newy = y-1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //RIGHT
    newx = x;
    newy = y+1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    } 
    //UP
    newx = x-1;
    newy = y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    
    visited[x][y]=0;    
}

vector<string>findpath(vector<vector<int>>&m,int n){
    vector<string>ans;
    if(m[0][0]==0){
        return ans;
    }
    int scrx = 0;
    int scry = 0;
    vector<vector<int>> visited = m;
    //initilize with 0
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           visited[i][j]=0;
       } 
    }
    string path = "";
    solve(m,n,ans,scrx,scry,visited,path);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<vector<int>>m ={{1,0,0,0},{1,1,0,1},{1,1,0,1},{0,1,1,1}};
    cout<<"THE MAZE IS"<<endl;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"THE PATH IS"<<endl;
    vector<string>ans = findpath(m,m.size());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}