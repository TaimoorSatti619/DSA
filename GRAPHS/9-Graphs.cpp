#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//// Shortest Path in Undirected Graph with Unit Weights

vector<int> shortestPath(vector<vector<int>> &edges, int src, int des) {

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_map<int, int> visted;
  unordered_map<int, int> parent;
  queue<int> q;
  q.push(src);
  visted[src] = true;
  parent[src] = -1;

  while (!q.empty()) {

    int front = q.front();
    q.pop();

    for (auto i : adj[front]) {
      if (!visted[i]) {
        visted[i] = true;
        parent[i] = front;
        q.push(i);
      }
    }
  }

  vector<int> ans;
  int currentNode = des;
  ans.push_back(currentNode);
  while (currentNode != src) {
    currentNode = parent[currentNode];
    ans.push_back(currentNode);
  }

  reverse(ans.begin(), ans.end());
  return ans;
}





///// Shortest Path in Undirected Graph with Unit Weights 

vector<int> shortestPath(vector<vector<int>> &edges, int src){

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++){
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int>dest(edges.size(), -1);
  vector<bool>visted(edges.size(), false);
  queue<int> q;

  q.push(src);
  visted[src] = true;
  dest[src] = 0;
  while (!q.empty()){
    int front = q.front();
    q.pop();

    for (auto i : adj[front]){
      if (!visted[i]){
        visted[i] = true;
        dest[i] = dest[front] + 1;
        q.push(i);
      }
    }
  }

  return dest;
}