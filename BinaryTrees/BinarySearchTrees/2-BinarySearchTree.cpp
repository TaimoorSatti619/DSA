#include <climits>
#include <iostream>
#include <vector>
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

/// Question 1  =>   Validate Binary Search Tree

bool checkBST(Node *root, int min, int max) {

  if (root == NULL) {
    return true;
  }

  if (root->data >= min && root->data <= max) {
    bool left = checkBST(root->left, min, root->data);
    bool right = checkBST(root->right, root->data, max);
    return left && right;
  } else {
    return false;
  }
}

bool isValidateBST(Node *root) { return checkBST(root, INT_MIN, INT_MAX); }

//********************************************************************************************

/// Question 2  =>    Kth Smallest Element in a BST

int kthSmallest(Node *root, int &i, int k) {

  if (root == NULL) {
    return -1;
  }

  int left = kthSmallest(root->left, i, k);
  if (left != -1) {
    return left;
  }

  i++;
  if (i == k) {
    return root->data;
  }

  return kthSmallest(root->right, i, k);
}

int KthSmallest(Node *root, int k) {
  int i = 0;
  int ans = kthSmallest(root, i, k);
  return ans;
}


/// Kth LArgest Element in a BST

int kthLargest(Node *root, int &i, int k){
  if (root == NULL){
    return -1;
  }

  int right = kthLargest(root->right, i, k);
  if (right != -1){
    return right;
  }

  i++;
  if (i == k){
    return root->data;
  }

  return kthLargest(root->left, i, k);
}



//********************************************************************************************

/// Question 3  =>   Predecessor and Successor in BST

vector<Node *> predecessorSuccessor(Node *root, int key){

  Node *pred = NULL;
  Node *succ = NULL;

  Node *temp = root;

  while (temp->data != key){

    if (temp->data > key){
      succ = temp;
      temp = temp->left;
    } else {
      pred = temp;
      temp = temp->right;
    }
  }

  Node* leftTree = temp->left;
  while (leftTree != NULL){
    pred = leftTree;
    leftTree = leftTree->right;
  }

  Node* rightTree = temp->right;
  while (rightTree != NULL){
    succ = rightTree;
    rightTree = rightTree->left;
  }

  return {pred, succ};
}


//********************************************************************************************


// Question 4  =>   Lowest Common Ancestor in a BST

Node* LCA(Node* root, Node* p, Node* q){

  while (root != NULL){

    if (root->data > p->data && root->data > q->data){
      root = root->left;
    }
    else if (root->data < p->data && root->data < q->data){
      root = root->right;
    }
    else{
      return root;
    }
  }
  return NULL;
}