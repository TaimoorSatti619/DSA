#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;



//// BFS Traversal  of Graph

void prepareAdjList(vector<pair<int,int>> edges,unordered_map<int,list<int>>&adjlist){

  for(int i=0;i<edges.size();i++){

    int u = edges[i].first;
    int v = edges[i].second;

    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }
}


void bfs(unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visted,vector<int>&ans,int node){
  
  queue<int>q;
  q.push(node);

  visted[node] = 1;

  while(!q.empty()){

    int frontNode = q.front();
    q.pop();

    // store frontNode into ans
    ans.push_back(frontNode);

    // traverse all neighbours of frontNode
    for(auto i:adjlist[frontNode]){
      if(!visted[i]){
        q.push(i);
        visted[i] = 1;
      }
    }
  }
}

vector<int> bfsOfGraph(int vertex,vector<pair<int,int>> edges){

  unordered_map<int,list<int>>adjlist;

  vector<int>ans;
  unordered_map<int,bool>visted;
  prepareAdjList(edges,adjlist);

  // traverse all components of a graph

  for(int i=0;i<vertex;i++){
    if(!visted[i]){
      bfs(adjlist,visted,ans,i);
    }
  }
  return ans; 
}