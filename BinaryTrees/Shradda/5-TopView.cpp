#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};



/////////////////////////////////////////////////////////////////

void topView(Node *root){
  
  map<int, int> m;
  queue<pair<Node*, int>> q;

  q.push({root, 0});
  
  while (q.size() > 0){

    Node* curr = q.front().first;
    int hd = q.front().second;
    q.pop();

    if (m.find(hd) == m.end()){
      m[hd] = curr->data;
    }

    if (curr->left != NULL){
      q.push({curr->left, hd - 1});
    }

    if (curr->right != NULL){
      q.push({curr->right, hd + 1});
    }    
  }

  for (auto i : m){
    cout << i.second << " ";
  }
}