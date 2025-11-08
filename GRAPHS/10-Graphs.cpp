#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/// Shortest Path in Directed Acyclic Graph

class Graph {
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void addEdge(int u, int v, int weight) {
    pair<int, int> p = make_pair(v, weight);
    adj[u].push_back(p);
  }

  void printAdj() {
    for (auto i : adj) {
      cout << i.first << "->";
      for (auto j : i.second) {
        cout << "(" << j.first << "," << j.second << "),";
      }
      cout << endl;
    }
  }

  void DFS(int node, unordered_map<int, bool> &visted, stack<int> &s) {

    visted[node] = true;

    for (auto i : adj[node]) {
      if (!visted[i.first]) {
        DFS(i.first, visted, s);
      }
    }

    s.push(node);
  }

  void shortestPath(stack<int> &s, int src, vector<int> &dist) {

    dist[src] = 0;

    while (!s.empty()) {

      int top = s.top();
      s.pop();

      if (dist[top] != INT_MAX) {
        for (auto i : adj[top]) {
          if (dist[top] + i.second < dist[i.first]) {
            dist[i.first] = dist[top] + i.second;
          }
        }
      }
    }
  }
};

int main() {

  Graph g;
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 3, 6);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);
  g.printAdj();

  int n = 6;

  /// topological sort
  unordered_map<int, bool> visted;
  stack<int> s;

  for (int i = 0; i < n; i++) {
    if (!visted[i]) {
      g.DFS(i, visted, s);
    }
  }

  int src = 1;
  vector<int> dist(n);
  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
  }

  g.shortestPath(s, src, dist);

  for (int i = 0; i < dist.size(); i++) {
    cout << dist[i] << " ";
  }
  cout << endl;

  return 0;
}