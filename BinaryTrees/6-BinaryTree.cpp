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

///   MINIMUM TIME TAKEN TO BURN THE BINARY TREE FROM A GIVEN TARGET NODE

Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent) {

  Node *res = NULL;

  queue<Node *> q;
  q.push(root);
  nodeToParent[root] = NULL;

  while (!q.empty()) {

    Node *front = q.front();
    q.pop();

    if (front->data == target) {
      res = front;
    }

    if (front->left) {
      nodeToParent[front->left] = front;
      q.push(front->left);
    }

    if (front->right) {
      nodeToParent[front->right] = front;
      q.push(front->right);
    }
  }

  return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent) {

  map<Node *, bool> visited;
  queue<Node *> q;
  q.push(root);
  visited[root] = true;
  int ans = 0;

  while (!q.empty()) {

    bool flag = false;
    int size = q.size();

    for (int i = 0; i < size; i++) {

      Node *front = q.front();
      q.pop();

      if (front->left && !visited[front->left]) {
        flag = true;
        q.push(front->left);
        visited[front->left] = true;
      }

      if (front->right && !visited[front->right]) {
        flag = true;
        q.push(front->right);
        visited[front->right] = true;
      }

      if (nodeToParent[front] && !visited[nodeToParent[front]]) {
        flag = true;
        q.push(nodeToParent[front]);
        visited[nodeToParent[front]] = true;
      }
    }

    if (flag == true) {
      ans++;
    }
  }

  return ans;
}

int amountOfTime(Node *root, int start) {

  if (root == NULL) {
    return 0;
  }

  map<Node *, Node *> nodeToParent;

  Node *targetNode = createMapping(root, start, nodeToParent);

  int ans = burnTree(targetNode, nodeToParent);

  return ans;
}