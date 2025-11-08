#include <iostream>
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

/////////////////////////////////////////

void KthLevel(Node *root, int k) {

  if (root == NULL) {
    return;
  }

  if (k == 1) {
    cout << root->data << " ";
    return;
  }

  KthLevel(root->left, k - 1);
  KthLevel(root->right, k - 1);
}