#include <climits>
#include <iostream>
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

// QUESTION 1  =>  SUM OF NODES OF LONGEST PATH FROM ROOT TO LEAF NODE

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen) {

  if (root == NULL) {
    if (len > maxLen) {
      maxLen = len;
      maxSum = sum;
    } else if (len == maxLen) {
      maxSum = max(sum, maxSum);
    }
    return;
  }

  sum += root->data;

  solve(root->left, sum, maxSum, len + 1, maxLen);
  solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongestPath(Node *root) {

  int len = 0;
  int maxLen = 0;
  int sum = 0;
  int maxSum = INT_MIN;

  solve(root, sum, maxSum, len, maxLen);
  return maxSum;
}

//********************************************************************************************

// LEETCODE 124  =>  BINARY TREE MAXIMUM PATH SUM

int solve(Node *root, int &maxi) {

  if (root == NULL) {
    return 0;
  }

  int leftSum = max(0, solve(root->left, maxi));
  int rightSum = max(0, solve(root->right, maxi));

  int currSum = leftSum + rightSum + root->data;
  maxi = max(maxi, currSum);
  return root->data + max(leftSum, rightSum);
}

int maxPathSum(Node *root) {

  int maxSum = INT_MIN;
  solve(root, maxSum);
  return maxSum;
}

// QUESTION 2  =>  LCA OF BINARY TREE

Node *lca(Node *root, int n1, int n2) {

  if (root == NULL) {
    return NULL;
  }

  if (root->data == n1 || root->data == n2) {
    return root;
  }

  Node *leftAns = lca(root->left, n1, n2);
  Node *rightAns = lca(root->right, n1, n2);

  if (leftAns != NULL && rightAns != NULL) {
    return root;
  } else if (leftAns != NULL && rightAns == NULL) {
    return leftAns;
  } else if (leftAns == NULL && rightAns != NULL) {
    return rightAns;
  } else {
    return NULL;
  }
}

//********************************************************************************************

// QUESTION 3  =>  K PATH SUM

void solve(Node *root, int k, vector<int> &path, int &cnt) {

  if (root == NULL) {
    return;
  }

  path.push_back(root->data);

  solve(root->left, k, path, cnt);
  solve(root->right, k, path, cnt);

  int size = path.size();
  int sum = 0;
  for (int i = size - 1; i >= 0; i--) {
    sum += path[i];
    if (sum == k) {
      cnt++;
    }
  }

  path.pop_back(); // not necessary
}

int sumK(Node *root, int k) {

  vector<int> path;
  int cnt = 0;
  solve(root, k, path, cnt);
  return cnt;
}

//*****************************************************************************************

// QUESTION 4  =>  KTH ANCESTOR OF NODE IN BINARY TREE

Node *solve(Node *root, int &k, int node) {

  if (root == NULL) {
    return NULL;
  }

  if (root->data == node) {
    return root;
  }

  Node *leftAns = solve(root->left, k, node);
  Node *rightAns = solve(root->right, k, node);

  if (leftAns != NULL && rightAns == NULL) {
    k--;
    if (k <= 0) {
      k = INT_MAX;
      return root;
    }
    return leftAns;
  }

  if (leftAns == NULL && rightAns != NULL) {
    k--;
    if (k <= 0) {
      k = INT_MAX;
      return root;
    }
    return rightAns;
  }

  return NULL;
}

int kthAncestor(Node *root, int k, int node) {

  Node *ans = solve(root, k, node);

  if (ans == NULL || ans->data == node) {
    return -1;
  } else {
    return ans->data;
  }
}

//*****************************************************************************************

// QUESTION 5  =>  MAXIMUM SUM OF NON-ADJACENT NODES

pair<int, int> solve(Node *root) {

  if (root == NULL) {
    return {0, 0};
  }

  pair<int, int> left = solve(root->left);
  pair<int, int> right = solve(root->right);

  pair<int, int> ans;
  ans.first = root->data + left.second + right.second;
  ans.second = max(left.first, left.second) + max(right.first, right.second);

  return ans;
}

int maxsum(Node *root) {

  pair<int, int> ans = solve(root);
  return max(ans.first, ans.second);
}

