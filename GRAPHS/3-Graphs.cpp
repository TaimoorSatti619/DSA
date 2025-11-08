#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visted, vector<int> &component) {

  component.push_back(node);
  visted[node] = 1;

  for (auto i : adj[node]) {
    if (!visted[i]) {
      dfs(i, adj, visted, component);
    }
  }
}


vector<vector<int> >depthFirstSearch(int V, int E, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adj;

  // create adj list
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> ans;
  unordered_map<int, bool> visted;

  // for unconnected graph

  for (int i = 0; i < edges.size(); i++) {

    if (!visted[i]) {
      vector<int> temp;
      dfs(i, adj, visted,
          temp); // if connected graph then dfs(0,adj,visted,temp);
      ans.push_back(temp);
    }
  }

  return ans;
}