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

// Question 1    =>     HEIGHT OF BINARY TREE

int height(Node *root) {
  if (root == NULL) {
    return 0;
  }

  int left = height(root->left);
  int right = height(root->right);

  int ans = max(left, right) + 1;
  return ans;
}


//*************************************************************************************************

// Question 2    =>    Count Nodes in a Binary Tree

int count(Node *root){
  if(root == NULL){
    return 0;
  }

  int left = count(root->left);
  int right = count(root->right);

  return left + right + 1;
}

//*************************************************************************************************

// Question 3    =>    Sum of Nodes in a Binary Tree

int sumOfNodes(Node *root){
  if(root == NULL){
    return 0;
  }

  int left = sumOfNodes(root->left);
  int right = sumOfNodes(root->right);

  return left + right + root->data;
}