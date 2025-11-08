#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

////// Bridges in Graph

void dfs(int node, int parent, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low,
         int &timer, vector<vector<int>> &result) {

  vis[node] = true;
  disc[node] = low[node] = timer++;

  for (auto nbr : adj[node]) {

    if (nbr == parent)
      continue;

    if (!vis[nbr]) {
      dfs(nbr, node, adj, vis, disc, low, timer, result);
      low[node] = min(low[node], low[nbr]);
      // check edge is bridge or not
      if (low[nbr] > disc[node]) {
        result.push_back({node, nbr});
      }

    } else {
      low[node] = min(low[node], disc[nbr]);
    }
  }
}

vector<vector<int>> findBridges(int n, vector<vector<int>> &edges) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> disc(n, -1);
  vector<int> low(n, -1);
  int parent = -1;

  unordered_map<int, bool> vis;
  vector<vector<int>> result;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, parent, adj, vis, disc, low, timer, result);
    }
  }

  return result;
}