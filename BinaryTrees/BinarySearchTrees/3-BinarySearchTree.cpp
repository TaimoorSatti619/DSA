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

/// Question 1  =>  Two Sum in Binary Search Tree

void inOrder(Node *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

bool twoSum(Node *root, int target) {

  vector<int> ans;
  inOrder(root, ans);

  int i = 0;
  int j = ans.size() - 1;

  while (i < j) {

    int sum = ans[i] + ans[j];

    if (sum == target) {
      return true;
    } else if (sum < target) {
      i++;
    } else {
      j--;
    }
  }

  return false;
}

//**********************************************************************************

/// Question 2  =>  Flatten Binary Tree to  Sorted Linked List

Node *flatten(Node *root) {

  vector<int> ans;
  inOrder(root, ans);

  Node *newRoot = new Node(ans[0]);
  Node *curr = newRoot;

  for (int i = 1; i < ans.size(); i++) {

    Node *temp = new Node(ans[i]);

    curr->left = NULL;
    curr->right = temp;
    curr = temp;
  }

  curr->left = NULL;
  curr->right = NULL;

  return newRoot;
}

//************************************************************************************

// Question 3  =>  Normal BST to Balanced BST

Node *createBalancedBST(vector<int> &ans, int start, int end) {

  if (start > end) {
    return NULL;
  }

  int mid = (start + end) / 2;

  Node *root = new Node(ans[mid]);
  root->left = createBalancedBST(ans, start, mid - 1);
  root->right = createBalancedBST(ans, mid + 1, end);
  return root;
}

Node *balancedBST(Node *root) {

  vector<int> ans;
  inOrder(root, ans);

  return createBalancedBST(ans, 0, ans.size() - 1);
}

//************************************************************************************/

// Question 4  =>  Construct BST from Preorder Traversal

Node *solve(vector<int> &preorder, int mini, int maxi, int &i) {

  if (i >= preorder.size()) {
    return NULL;
  }

  if (preorder[i] < mini || preorder[i] > maxi) {
    return NULL;
  }

  Node *root = new Node(preorder[i++]);

  root->left = solve(preorder, mini, root->data, i);
  root->right = solve(preorder, root->data, maxi, i);

  return root;
}

Node *bstFromPreorder(vector<int> &preorder) {

  int mini = INT_MIN;
  int maxi = INT_MAX;
  int i = 0;
  return solve(preorder, mini, maxi, i);
}

//**********************************************************************************************************

/////  Addiional Questions

/// Convert Sorted List to Binary Search Tree

void Solve(Node *head, vector<int> &ans) {

  while (head != NULL) {
    ans.push_back(head->data);
    head = head->next;
  }
}

Node *BST(vector<int> &ans, int start, int end) {

  if (start > end) {
    return NULL;
  }

  int mid = (start + end) / 2;

  Node *root = new Node(ans[mid]);
  root->left = BST(ans, start, mid - 1);
  root->right = BST(ans, mid + 1, end);

  return root;
}

Node *sortedListToBST(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  vector<int> ans;
  Solve(head, ans);

  return BST(ans, 0, ans.size() - 1);
}

/// Convert Sorted Array to Binary Search Tree

Node *sortedArrayToBST(vector<int> &nums) {

  return BST(nums, 0, nums.size() - 1);
}
