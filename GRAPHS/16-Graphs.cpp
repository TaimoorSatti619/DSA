#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;



/////// Kosaraju's Algorithm for Strongly Connected Components

void topoDfs(int node, unordered_map<int, list<int>> &adj, stack<int> &st, unordered_map<int, bool> &vis){

  vis[node] = true;

  for (auto nbr : adj[node]){
      if (!vis[nbr]){
         topoDfs(nbr, adj, st, vis);
      }
   }
   st.push(node);
}


void Dfs(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &vis){

  vis[node] = true;

  for (auto nbr : transpose[node]){
     if (!vis[nbr]){
        Dfs(nbr, transpose, vis);
     }
  }
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges){

   unordered_map<int, list<int>> adj;
   for (int i = 0; i < edges.size(); i++){
      int u = edges[i][0];
      int v = edges[i][1];

     adj[u].push_back(v);
   }


   unordered_map<int, bool> vis;
   stack<int> st;

  //// Step 1: Topological Sort
  for (int i = 0; i < n; i++){
     if (!vis[i]){
        topoDfs(i, adj, st, vis);
     }
  }


  /// Step 2: Transpose the graph
  unordered_map<int, list<int>> transpose;
  for (int i = 0; i < n; i++){
      vis[i] = false;
      for (auto nbr : adj[i]){
         transpose[nbr].push_back(i);
      }
  }


  //// step 3: DFS on transpose graph
  int cnt = 0;
  while (!st.empty()){
      int top = st.top();
      st.pop();

     if (!vis[top]){
         cnt++;
         Dfs(top, transpose,vis);
      }
  }

  return cnt; 
}