#include <algorithm>
#include <iostream>
#include <map>
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

// Question 1    =>     ZIG-ZAG TRAVERSAL

vector<int> zigZagTraversal(Node *root) {

  vector<int> result;
  if (root == NULL) {
    return result;
  }

  queue<Node *> q;
  q.push(root);
  bool leftToRight = true;

  while (!q.empty()) {

    int size = q.size();
    vector<int> ans(size);

    for (int i = 0; i < size; i++) {

      Node *frontNode = q.front();
      q.pop();

      int index = leftToRight ? i : size - i - 1;
      ans[index] = frontNode->data;

      if (frontNode->left) {
        q.push(frontNode->left);
      }

      if (frontNode->right) {
        q.push(frontNode->right);
      }
    }

    leftToRight = !leftToRight;

    for (auto i : ans) {
      result.push_back(i);
    }
  }

  return result;
}

//*************************************************************************************************

// Question 2    =>     BOUNDARY TRAVERSAL

void traverseLeft(Node *root, vector<int> &ans) {

  if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
    return;
  }

  ans.push_back(root->data);

  if (root->left) {
    traverseLeft(root->left, ans);
  } else {
    traverseLeft(root->right, ans);
  }
}

void traverseLeaf(Node *root, vector<int> &ans) {

  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    ans.push_back(root->data);
    return;
  }

  traverseLeaf(root->left, ans);
  traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans) {

  if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
    return;
  }

  if (root->right) {
    traverseRight(root->right, ans);
  } else {
    traverseRight(root->left, ans);
  }

  ans.push_back(root->data);
}

///////////////////

vector<int> boundaryTraversal(Node *root) {

  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  ans.push_back(root->data);

  traverseLeft(root->left, ans);

  traverseLeaf(root, ans);
  traverseLeaf(root->left, ans);

  traverseRight(root->right, ans);

  return ans;
}

//*************************************************************************************************

// Question 3    =>     VERTICAL ORDER TRAVERSAL

vector<vector<int>> verticalOrderTraversal(Node *root) {

  vector<vector<int>> ans;
  map<int, map<int, vector<int>>> nodes;
  queue<pair<Node *, pair<int, int>>> q;

  if (root == NULL) {
    return ans;
  }

  q.push({root, {0, 0}});

  while (!q.empty()) {

    pair<Node *, pair<int, int>> temp = q.front();
    q.pop();

    Node *frontNode = temp.first;
    int hd = temp.second.first;
    int lvl = temp.second.second;

    nodes[hd][lvl].push_back(frontNode->data);

    if (frontNode->left) {
      q.push({frontNode->left, {hd - 1, lvl + 1}});
    }

    if (frontNode->right) {
      q.push({frontNode->right, {hd + 1, lvl + 1}});
    }
  }

  for (auto i : nodes) {
    vector<int> col;
    for (auto j : i.second) {
      vector<int> &temp = j.second;
      sort(temp.begin(), temp.end()); // Sorting is important
      col.insert(col.end(), temp.begin(), temp.end());
    }
    ans.push_back(col);
  }

  return ans;
}

//*************************************************************************************************

// Question 4    =>     TOP VIEW Of BINARY TREE

vector<int> topView(Node *root) {

  vector<int> ans;
  if (root == NULL) {
    return ans;
  }

  map<int, int> topNode;
  queue<pair<Node *, int>> q;

  q.push({root, 0});

  while (!q.empty()) {

    pair<Node *, int> temp = q.front();
    q.pop();

    Node *frontNode = temp.first;
    int hd = temp.second;

    if (topNode.find(hd) == topNode.end()) {
      topNode[hd] = frontNode->data;
    }

    if (frontNode->left) {
      q.push({frontNode->left, hd - 1});
    }

    if (frontNode->right) {
      q.push({frontNode->right, hd + 1});
    }
  }

  for (auto i : topNode) {
    ans.push_back(i.second);
  }

  return ans;
}

//*************************************************************************************************

// Question 5    =>     BOTTOM VIEW Of BINARY TREE

vector<int> bottomView(Node *root) {

  vector<int> ans;
  if (root == NULL) {
    return ans;
  }

  map<int, int> bottomNode;
  queue<pair<Node *, int>> q;

  q.push({root, 0});

  while (!q.empty()) {

    pair<Node *, int> temp = q.front();
    q.pop();

    Node *frontNode = temp.first;
    int hd = temp.second;

    bottomNode[hd] = frontNode->data;

    if (frontNode->left) {
      q.push({frontNode->left, hd - 1});
    }

    if (frontNode->right) {
      q.push({frontNode->right, hd + 1});
    }
  }

  for (auto i : bottomNode) {
    ans.push_back(i.second);
  }

  return ans;
}

//*************************************************************************************************

// Question 6    =>     LEFT VIEW Of BINARY TREE

void solve(Node *root, vector<int> &ans, int lvl) {

  if (root == NULL) {
    return;
  }

  if (lvl == ans.size()) {
    ans.push_back(root->data);
  }

  solve(root->left, ans, lvl + 1);
  solve(root->right, ans, lvl + 1);
}

vector<int> leftView(Node *root) {

  vector<int> ans;
  solve(root, ans, 0);
  return ans;
}

//*************************************************************************************************

// Question 7    =>     RIGHT VIEW Of BINARY TREE

void solve(Node *root, vector<int> &ans, int lvl) {

  if (root == NULL) {
    return;
  }

  if (lvl == ans.size()) {
    ans.push_back(root->data);
  }

  solve(root->right, ans, lvl + 1);
  solve(root->left, ans, lvl + 1);
}

vector<int> rightView(Node *root) {

  vector<int> ans;
  solve(root, ans, 0);
  return ans;
}

//*************************************************************************************************

// Question 8    =>    Diagonal Traversal Of Binary Tree

vector<int> diagonalTraversal(Node *root) {

  vector<int> ans;
  if (root == NULL) {
    return ans;
  }

  queue<Node *> q;

  q.push(root);

  while (!q.empty()) {

    Node *temp = q.front();
    q.pop();

    while (temp != NULL) {
      ans.push_back(temp->data);

      if (temp->left) {
        q.push(temp->left);
      }
      temp = temp->right;
    }
  }

  return ans;
}

//*************************************************************************************************