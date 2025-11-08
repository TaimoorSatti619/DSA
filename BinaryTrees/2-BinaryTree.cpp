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

// Question 2    =>     DIAMETER OF BINARY TREE

pair<int, int> diameterFast(Node *root) {
  if (root == NULL) {
    return {0, 0}; // {0,-1} bhi return kar sakte hain
  }

  pair<int, int> left = diameterFast(root->left);
  pair<int, int> right = diameterFast(root->right);

  int op1 = left.first;
  int op2 = right.first;
  int op3 = left.second + right.second + 1; // kabhi oper {0,-1} return karte hain toh +1 ki jaga 2 karna padega

  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));
  ans.second = max(left.second, right.second) + 1;

  return ans;
}

int diameter(Node *root) { return diameterFast(root).first; }

//*************************************************************************************************

// Question 3    =>     CHECK IF TREE IS BALANCED OR NOT

pair<bool, int> balancedFast(Node *root) {
  if (root == NULL) {
    return {true, 0};
  }

  pair<bool, int> left = balancedFast(root->left);
  pair<bool, int> right = balancedFast(root->right);

  bool leftAns = left.first;
  bool rightAns = right.first;
  bool diff = abs(left.second - right.second) <= 1;

  pair<bool, int> ans;
  ans.second = max(left.second, right.second) + 1;

  if (leftAns && rightAns && diff) {
    ans.first = true;
  } else {
    ans.first = false;
  }

  return ans;
}

bool isBalanced(Node *root) { return balancedFast(root).first; }

//*************************************************************************************************

// Question 4    =>     Determine if two trees are identical

bool isidentical(Node *root1, Node *root2) {
  if (root1 == NULL && root2 == NULL) {
    return true;
  }

  if (root1 == NULL && root2 != NULL) {
    return false;
  }

  if (root1 != NULL && root2 == NULL) {
    return false;
  }

  bool left = isidentical(root1->left, root2->left);
  bool right = isidentical(root1->right, root2->right);
  bool value = root1->data == root2->data;

  if (left && right && value) {
    return true;
  } else {
    return false;
  }
}

//*************************************************************************************************

// Question 5    =>     SUM TREE or NOT

pair<bool, int> sumTreeFast(Node *root) {

  if (root == NULL) {
    return {true, 0};
  }

  if (root->left == NULL && root->right == NULL) {
    return {true, root->data};
  }

  pair<bool, int> left = sumTreeFast(root->left);
  pair<bool, int> right = sumTreeFast(root->right);

  bool leftAns = left.first;
  bool rightAns = right.first;

  int leftSum = left.second;
  int rightSum = right.second;

  bool condition = root->data == leftSum + rightSum;

  pair<bool, int> ans;
  if (leftAns && rightAns && condition) {
    ans.first = true;
    ans.second = root->data + leftSum + rightSum;
  } else {
    ans.first = false;
  }

  return ans;
}

bool isSumTree(Node *root) { return sumTreeFast(root).first; }

//*************************************************************************************************