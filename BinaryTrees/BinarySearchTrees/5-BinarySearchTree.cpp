#include <climits>
#include <iostream>
#include <queue>
#include <vector>
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

///// LARGEST BST IN A BINARY TREE

class info {
public:
  int maxi;
  int mini;
  bool isBST;
  int size;
};

info solve(Node *root, int &maxSize) {

  if (root == NULL) {
    return {INT_MAX, INT_MIN, true, 0};
  }

  info left = solve(root->left, maxSize);
  info right = solve(root->right, maxSize);

  info curr;

  curr.size = left.size + right.size + 1;
  curr.maxi = max(root->data, right.maxi);
  curr.mini = min(root->data, left.mini);

  if (left.isBST && right.isBST && root->data > left.maxi &&
      root->data < right.mini) {
    curr.isBST = true;
  } else {
    curr.isBST = false;
  }

  if (curr.isBST) {
    maxSize = max(maxSize, curr.size);
  }

  return curr;
}

int maxSizeBst(Node *root) {
  int maxSize = 0;
  info temp = solve(root, maxSize);
  return maxSize;
}
