#include <iostream>
#include <map>
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

// QUESTION 1  =>  CONSTRUCT BINARY TREE FROM INORDER AND PREORDER

void createMaping(vector<int> &inorder, map<int, int> &mp) {

  for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
  }
}

Node *solve(vector<int> &inorder, vector<int> &preorder, int &idx,
            int inorderStart, int inorderEnd, int n, map<int, int> &mp) {

  // base case
  if (idx >= n || inorderStart > inorderEnd) {
    return NULL;
  }

  int element = preorder[idx++];
  Node *root = new Node(element);
  int position = mp[element];

  // recursive calls
  root->left = solve(inorder, preorder, idx, inorderStart, position - 1, n, mp);
  root->right = solve(inorder, preorder, idx, position + 1, inorderEnd, n, mp);

  return root;
}

Node *BuildTree(vector<int> &inorder, vector<int> &preorder) {

  int n = inorder.size();

  int preIndex = 0;

  map<int, int> mp;
  createMaping(inorder, mp);

  Node *ans = solve(inorder, preorder, preIndex, 0, n - 1, n, mp);

  return ans;
}

//*****************************************************************************************

// QUESTION 2  =>  CONSTRUCT BINARY TREE FROM INORDER AND POSTORDER

Node *Solve(vector<int> &inorder, vector<int> &postorder, int &postIndex,
            int inorderStart, int inorderEnd, int n, map<int, int> &mp) {

  // base case
  if (postIndex < 0 || inorderStart > inorderEnd) {
    return NULL;
  }

  int element = postorder[postIndex--];
  Node *root = new Node(element);
  int position = mp[element];

  // recursive calls
  root->right =
      Solve(inorder, postorder, postIndex, position + 1, inorderEnd, n, mp);
  root->left =
      Solve(inorder, postorder, postIndex, inorderStart, position - 1, n, mp);

  return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder) {

  int n = inorder.size();
  int postIndex = n - 1;

  map<int, int> mp;
  createMaping(inorder, mp);

  Node *ans = Solve(inorder, postorder, postIndex, 0, n - 1, n, mp);
  return ans;
}