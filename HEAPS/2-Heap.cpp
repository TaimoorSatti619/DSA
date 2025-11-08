#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// Question 1 =>  Kth Smallest Element

int kthSmallest(vector<int> &arr, int k) {

  priority_queue<int> pq;

  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  for (int i = k; i < arr.size(); i++) {
    if (arr[i] < pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  int ans = pq.top();
  return ans;
}

//****************************************************************

/// => Kth Largest Element

int kthLargest(vector<int> &arr, int k) {

  priority_queue<int, vector<int>, greater<int>> minheap;

  for (int i = 0; i < k; i++) {
    minheap.push(arr[i]);
  }

  for (int i = k; i < arr.size(); i++) {
    if (arr[i] > minheap.top()) {
      minheap.pop();
      minheap.push(arr[i]);
    }
  }

  int ans = minheap.top();
  return ans;
}

////*******************************************************************************

// Question 2 =>  IS BINARY TREE HEAP

int countNodes(Node *tree) {

  if (tree == NULL) {
    return 0;
  }

  int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
  return ans;
}

bool CBT(Node *tree, int index, int totalNodes) {

  if (tree == NULL) {
    return true;
  }

  if (index >= totalNodes) {
    return false;
  } else {

    bool left = CBT(tree->left, 2 * index + 1, totalNodes);
    bool right = CBT(tree->right, 2 * index + 2, totalNodes);

    return (left && right);
  }
}

bool isMaxOrder(Node *tree) {

  if (tree->left == NULL && tree->right == NULL) {
    return true;
  }

  if (tree->right == NULL) {
    return (tree->data > tree->left->data);
  } else {

    bool left = isMaxOrder(tree->left);
    bool right = isMaxOrder(tree->right);

    return (left && right && (tree->data > tree->left->data) &&
            (tree->data > tree->right->data));
  }
}

bool isHeap(Node *tree) {

  int index = 0;
  int totalNodes = countNodes(tree);

  if (CBT(tree, index, totalNodes) && isMaxOrder(tree)) {
    return true;
  } else {
    return false;
  }
}

////*******************************************************************************

/// Question 3 =>  MERGE TWO BINARY MAX HEAPS

void Heapify(vector<int> &arr, int n, int i) {

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[largest] < arr[left]) {
    largest = left;
  }

  if (right < n && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[largest], arr[i]);
    Heapify(arr, n, largest);
  }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

  vector<int> ans;

  for (auto x : a) {
    ans.push_back(x);
  }

  for (auto x : b) {
    ans.push_back(x);
  }

  int size = ans.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    Heapify(ans, size, i);
  }

  return ans;
}

///*********************************************************************

/// Question 4 =>  MINIMUM COST OF ROPES

int minCost(int arr[], int n) {

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    pq.push(arr[i]);
  }

  int cost = 0;

  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();

    int sum = a + b;
    cost += sum;

    pq.push(sum);
  }

  return cost;
}

///*********************************************************************

/// Question 5 =>  Convert BST to Min Heap

void inorderTraversal(Node *root, vector<int> &inorder) {

  if (root == NULL) {
    return;
  }

  inorderTraversal(root->left, inorder);
  inorder.push_back(root->data);
  inorderTraversal(root->right, inorder);
}

void preorderTraversal(Node *root, vector<int> &inorder, int &i) {

  if (root == NULL) {
    return;
  }

  root->data = inorder[i++];

  preorderTraversal(root->left, inorder, i);
  preorderTraversal(root->right, inorder, i);
}

void BSTtoMinHeap(Node *root) {

  vector<int> inorder;
  inorderTraversal(root, inorder);

  int i = 0;

  preorderTraversal(root, inorder, i);
}



//// Convert BST to Max Heap

void InOrder(Node *root, vector<int> &inorder, int &i) {

  if (root == NULL) {
    return;
  }

  InOrder(root->left, inorder, i);
  inorder.push_back(root->data);
  InOrder(root->right, inorder, i);
  root->data = inorder[i++];
}

void BSTtoMaxHeap(Node *root) {

  int i = 0;
  vector<int> inorder;
  inorderTraversal(root, inorder, i);

  // reverse(inorder.begin(), inorder.end());

  // int i = 0;
  //  preorderTraversal(root, inorder, i);
}