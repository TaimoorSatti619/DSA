#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//// Topological Sort using BFS (Kahn's Algorithm)

vector<int> topoSort(int v, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);

    // inDegree[v]++;
  }

  // find all indegree
  vector<int> indegree(v);
  for (auto i : adj) {

    for (auto j : i.second) {
      indegree[j]++;
    }
  }

  // 0 indegree ko queue me daal do
  queue<int> q;
  for (int i = 0; i < v; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // BFS
  vector<int> ans;
  while (!q.empty()) {
    int front = q.front();
    q.pop();

    // ans store
    ans.push_back(front);

    // neighbour ko indegree kam karo
    for (auto i : adj[front]) {
      indegree[i]--;
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
  }

  return ans;
}