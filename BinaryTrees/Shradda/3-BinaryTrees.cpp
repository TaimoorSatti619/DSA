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

// Question 1    =>     Identical Trees

bool identical(Node *root1, Node *root2) {

  if (root1 == NULL || root2 == NULL) {
    return root1 == root2;
  }

  bool left = identical(root1->left, root2->left);
  bool right = identical(root1->right, root2->right);

  return (root1->data == root2->data && left && right);
}

//*************************************************************************************************

// Question 2    =>    SUBTREE OF ANOTHER TREE

bool isSubtree(Node *root, Node *subTree){

  if(root == NULL || subTree == NULL){
    return root == subTree;
  }

  if(root->data == subTree->data && identical(root, subTree)){
    return true;
  }

  return isSubtree(root->left, subTree) || isSubtree(root->right, subTree);
}