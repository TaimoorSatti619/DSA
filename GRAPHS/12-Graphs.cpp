#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/////// PRIM'S ALGORITHM    ==> MINIMUM SPANNING TREE

vector<pair<pair<int, int>, int>>
primsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

  // create a graph
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < g.size(); i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> key(n + 1, INT_MAX);
  vector<bool> mst(n + 1, false);
  vector<int> parent(n + 1, -1);

  // lets start the algo
  key[1] = 0;
  parent[1] = -1;

  for (int i = 1; i < n; i++) {

    int mini = INT_MAX;
    int u;

    // find the min wali node
    for (int j = 1; j <= n; j++) {
      if (mst[j] == false && key[j] < mini) {
        u = j;
        mini = key[j];
      }
    }

    // mark min node as true
    mst[u] = true;

    // explore the neighbours of min node
    for (auto it : adj[u]) {
      int v = it.first;
      int w = it.second;

      if (mst[v] == false && w < key[v]) {
        parent[v] = u;
        key[v] = w;
      }
    }
  }

  vector<pair<pair<int, int>, int>> result;

  for (int i = 2; i <= n; i++) {
    result.push_back({{parent[i], i}, key[i]});
  }

  return result;
}

//////////////////////////////////////////////////////////////////////

///// USING PRIORITY QUEUE  MIN HEAP

vector<pair<pair<int, int>, int>>
primsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

  // create a graph
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < g.size(); i++) {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> key(n + 1, INT_MAX);
  vector<bool> mst(n + 1, false);
  vector<int> parent(n + 1, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // lets start the algo
  key[1] = 0;
  parent[1] = -1;
  pq.push({0, 1});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    mst[u] = true;
    for (auto it : adj[u]) {
      int v = it.first;
      int w = it.second;

      if (mst[v] == false && w < key[v]) {
        parent[v] = u;
        key[v] = w;
        pq.push({key[v], v});
      }
    }
  }

  vector<pair<pair<int, int>, int>> result;
  for (int i = 2; i <= n; i++) {
    result.push_back({{parent[i], i}, key[i]});
  }
  return result;
}