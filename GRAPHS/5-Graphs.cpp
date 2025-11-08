#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/// Cycle Detection in Directed Graph using DFS

bool DFS(int node, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visted,
         unordered_map<int, bool> &dfsVisted) {

  visted[node] = true;
  dfsVisted[node] = true;

  for (auto i : adj[node]) {
    if (!visted[i]) {
      bool cycleDetected = DFS(i, adj, visted, dfsVisted);
      if (cycleDetected)
        return true;
    } else if (dfsVisted[i]) {
      return true;
    }
  }
  dfsVisted[node] = false;
  return false;
}

bool isCycle(vector<vector<int>> &edges, int v) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < v; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visted;
  unordered_map<int, bool> dfsVisted;

  for (int i = 1; i <= adj.size(); i++) {
    if (!visted[i]) {
      if (DFS(i, adj, visted, dfsVisted))
        return true;
    }
  }
  return false;
}