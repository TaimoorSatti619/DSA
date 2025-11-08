#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//// Cycle Detection in Undirected Graph using BFS

bool BFS(int src, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visted) {

  unordered_map<int, int> parent;
  parent[src] = -1;

  queue<int> q;
  q.push(src);

  visted[src] = true;

  while (!q.empty()) {

    int front = q.front();
    q.pop();

    for (auto i : adj[front]) {

      if (visted[i] == true && i != parent[front]) {
        return true;
      } else if (!visted[i]) {
        q.push(i);
        visted[i] = true;
        parent[i] = front;
      }
    }
  }

  return false;
}

/// Cycle Detection in Undirected Graph using DFS

bool DFS(int node, int parent, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visted) {

  visted[node] = true;

  for (auto i : adj[node]) {

    if (!visted[i]) {
      bool cycleDetected = DFS(i, node, adj, visted);
      if (cycleDetected)
        return true;
    } else if (i != parent) {
      // cycle detected
      return true;
    }
  }

  return false;
}



bool isCycle(int v, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < v; i++) {

    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_map<int, bool> visted;
  for (int i = 0; i < v; i++) {
    if (!visted[i]) {
      // if (DFS(i, -1, adj, visted))     // DFS method
      if (BFS(i, adj, visted))
        return true;
    }
  }

  return false;
}