#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

//// Dijkstra's Algorithm

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int src) {

  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges; i++) {

    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  vector<int> dist(vertices, INT_MAX);

  set<pair<int, int>> st;

  dist[src] = 0;
  st.insert(make_pair(0, src));

  while (!st.empty()) {

    // fetch top record
    auto top = *(st.begin());

    int nodeDistance = top.first;
    int topNode = top.second;

    // remove top record
    st.erase(st.begin());

    // iterate over neighbours
    for (auto i : adj[topNode]) {

      if (nodeDistance + i.second < dist[i.first]) {

        auto record = st.find(make_pair(dist[i.first], i.first));

        // if record found, then erase it
        if (record != st.end()) {
          st.erase(record);
        }

        // update distance
        dist[i.first] = nodeDistance + i.second;

        // record push in set
        st.insert(make_pair(dist[i.first], i.first));
      }
    }
  }

  return dist;
}