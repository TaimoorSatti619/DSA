#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// ordered map   => O(logn)     BST
// unordered map => O(1)         Hash Table

int main() {

  // creation
  unordered_map<string, int> m;

  // insertion
  // 1
  pair<string, int> p = make_pair("alien", 3);
  m.insert(p);

  // 2
  pair<string, int> pair2("alone", 2);
  m.insert(pair2);

  // 3
  m["abc"] = 1;

  // search
  cout << m["abc"] << endl;
  cout << m.at("abc") << endl;

  cout << m["xyz"] << endl;    // creates a key with value 0
  cout << m.at("xyz") << endl; // throws error

  // size
  cout << m.size() << endl;

  // to check presence
  cout << m.count("abc") << endl;

  // erase
  m.erase("abc");
  cout << m.size() << endl;

  // traversal
  unordered_map<string, int>::iterator it = m.begin();
  while (it != m.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  return 0;
}

/// Question 1  =>  Count elements with maximum frequency

int maxFrequency(vector<int> arr) {
  unordered_map<int, int> m;

  int maxFreq = 0;
  int maxAns = 0;
  for (int i = 0; i < arr.size(); i++) {
    m[arr[i]]++;
    maxFreq = max(maxFreq, m[arr[i]]);
  }

  for (int i = 0; i < arr.size(); i++) {
    if (m[arr[i]] == maxFreq) {
      maxAns = arr[i];
      break;
    }
  }

  return maxAns;
}