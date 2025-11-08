#include <iostream>
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

/// Question 1 =>  Morris Traversal (Inorder Traversal without recursion and
/// without stack)

vector<int> morrisTraversal(Node *root) {

  vector<int> ans;
  Node *curr = root;

  while (curr != NULL) {

    if (curr->left == NULL) {
      ans.push_back(curr->data);
      curr = curr->right;
    } else {

      Node *prev = curr->left;
      while (prev->right != NULL && prev->right != curr) {
        prev = prev->right;
      }

      if (prev->right == NULL) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = NULL;
        ans.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  return ans;
}

//******************************************************************************************

// Question 2 =>  Flatten Binary Tree to Linked List

void flatten(Node *root) {

  if (root == NULL) {
    return;
  }

  Node *curr = root;

  while (curr != NULL) {

    if (curr->left) {

      Node *pred = curr->left;
      while (pred->right) {
        pred = pred->right;
      }

      pred->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }

    curr = curr->right;
  }
}


