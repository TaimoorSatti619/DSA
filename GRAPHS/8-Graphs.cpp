#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


//// Cycle Detection in Directed Graph using BFS (Kahn's Algorithm)

bool isCycle(vector<vector<int>> &edges, int v){

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++){
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  // find all indegree
  vector<int> indegree(v);
  for (auto i : adj){
    for (auto j : i.second){
      indegree[j]++;
    }
  }

  // 0 indegree ko queue me daal do
  queue<int> q;
  for (int i = 0; i < v; i++){
    if (indegree[i] == 0){
      q.push(i);
    }
  }

  int cnt = 0;
  while (!q.empty()){

    int front = q.front();
    q.pop();

    cnt++;

    // neighbour ko indegree kam karo
    for (auto i : adj[front]){
      indegree[i]--;
      if (indegree[i] == 0){
        q.push(i);
      }
    }
  }

  if (cnt == v){
    return false;
  }
  else{
    return true;
  }
}