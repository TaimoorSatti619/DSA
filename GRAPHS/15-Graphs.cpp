#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//////////////// Articulation Points in Graph

void dfs(int node, int parent, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low,
         int &timer, vector<int> &ap) {

  vis[node] = true;
  disc[node] = low[node] = timer++;

  int child = 0;
  for (auto nbr : adj[node]) {
    if (parent == nbr) {
      continue;
    }

    if (!vis[nbr]) {
      dfs(nbr, node, adj, vis, disc, low, timer, ap);
      low[node] = min(low[node], low[nbr]);
      // check for articulation point
      if (low[nbr] >= disc[node] && parent != -1) {
        ap[node] = 1;
      }
      child++;
    } else {
      low[node] = min(low[node], disc[nbr]);
    }
  }
  if (parent == -1 && child > 1) {
    ap[node] = 1;
  }
}

vector<int> articulationPoints(int n, vector<vector<int>> &edges) {

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
  unordered_map<int, bool> vis;
  vector<int> ap(n, 0);

  // DFS
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, -1, adj, vis, disc, low, timer, ap);
    }
  }

  vector<int> result;
  for (int i = 0; i < n; i++) {
    if (ap[i] == 1) {
      result.push_back(i);
    }
  }
  return result;
}