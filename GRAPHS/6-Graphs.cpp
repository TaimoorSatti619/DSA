#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/// Topological Sort using DFS

void DFS(int node, unordered_map<int, list<int>> &adj, vector<bool> &visted,
         stack<int> &s) {

  visted[node] = true;

  for (auto i : adj[node]) {
    if (!visted[i]) {
      DFS(i, adj, visted, s);
    }
  }

  // imp
  s.push(node);
}

vector<int> topoSort(int v, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  vector<bool> visted(v);
  stack<int> s;

  for (int i = 0; i < v; i++) {
    if (!visted[i]) {
      DFS(i, adj, visted, s);
    }
  }

  vector<int> ans;
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }

  return ans;
}