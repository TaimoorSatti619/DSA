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


void allPaths(Node *root, vector<string> &ans, string path){

  if(root->left == NULL && root->right == NULL){
    ans.push_back(path);
    return;
  }

  if(root->left){
    allPaths(root->left, ans, path + "->" + to_string(root->left->data));
  }

  if(root->right){
    allPaths(root->right, ans, path + "->" + to_string(root->right->data));
  }
  
}


vector<string> binaryTreePaths(Node *root){
  vector<string> ans;
  string path = to_string(root->data);
  allPaths(root, ans, path);
  return ans;
}