#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

///////////  BELLEMAN FORD ALGORITHM   ==>  SHORTEST PATH ALGORITHM    ==> WORKS
/// WITH NEGATIVE WEIGHTS

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

  vector<int> dist(n + 1, 1e8);
  dist[src] = 0;

  for (int i = 1; i <= n; i++) {
    // treverse on edge list
    for (int j = 0; j < m; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if (dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  //   return dist[dest];

  // check for negative weight cycle
  bool flag = false;
  for (int j = 0; j < m; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int wt = edges[j][2];

    if (dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
      flag = true;
    }
  }

  if (flag) {
    return 1e8;
  }
  return dist[dest];
}
