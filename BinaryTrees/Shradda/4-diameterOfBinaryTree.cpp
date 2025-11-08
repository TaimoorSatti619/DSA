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



//   O(N^2) 
int height(Node *root){
  if(root == NULL){
    return 0;
  }

  int leftHt = height(root->left);
  int rightHt = height(root->right);

  return max(leftHt, rightHt) + 1;
}

int diameterOfBinaryTree(Node *root){
  if(root == NULL){
    return 0;
  }

  int leftDia = diameterOfBinaryTree(root->left);
  int rightDia = diameterOfBinaryTree(root->right);

  int currDia = height(root->left) + height(root->right);
  return max(currDia, max(leftDia, rightDia));
}


//********************************************************************************************



//   O(N)

int ans = 0;

int solve(Node *root){
  
  if(root == NULL){
    return 0;
  }

  int leftHt = solve(root->left);
  int rightHt = solve(root->right);

  ans = max(ans, leftHt + rightHt);
  return max(leftHt, rightHt) + 1;
}


