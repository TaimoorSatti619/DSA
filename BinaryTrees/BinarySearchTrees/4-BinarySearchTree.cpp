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

/// Question 1  =>  MERGE TWO BINARY SEARCH TREES

// Approach 1       T.C  => O(M+N)   S.C  => O(M+N)

void inOrder(Node *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

vector<int> mergeTwoArrays(vector<int> &arr1, vector<int> &arr2) {

  vector<int> ans(arr1.size() + arr2.size());
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < arr1.size() && j < arr2.size()) {

    if (arr1[i] < arr2[j]) {
      ans[k++] = arr1[i++];
    } else {
      ans[k++] = arr2[j++];
    }
  }

  while (i < arr1.size()) {
    ans[k++] = arr1[i++];
  }
  while (j < arr2.size()) {
    ans[k++] = arr2[j++];
  }

  return ans;
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

///

Node *mergeBST(Node *root1, Node *root2) {
  vector<int> arr1;
  vector<int> arr2;
  inOrder(root1, arr1);
  inOrder(root2, arr2);
  vector<int> ans = mergeTwoArrays(arr1, arr2);
  return BST(ans, 0, ans.size() - 1);
}

///***********************************************************************************

/// Convert BST to Sorted Doubly Linked List

void convertBSTtoDLL(Node *root, Node *&head) {

  if (root == NULL) {
    return;
  }

  convertBSTtoDLL(root->right, head);
  root->right = head;

  if (head != NULL) {
    head->left = root;
  }

  head = root;
  convertBSTtoDLL(root->left, head);
}

/// Merge Two Sorted Doubly Linked List

Node *mergeTwoDLL(Node *head1, Node *head2) {

  Node *head = NULL;
  Node *tail = NULL;

  while (head1 != NULL && head2 != NULL) {

    if (head1->data < head2->data) {

      if (head == NULL) {
        head = head1;
        tail = head1;
        head1 = head1->right;
      } else {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
      }
    } else {

      if (head == NULL) {
        head = head2;
        tail = head2;
        head2 = head2->right;
      } else {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
      }
    }
  }

  while (head1 != NULL) {
    tail->right = head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
  }

  while (head2 != NULL) {
    tail->right = head2;
    head2->left = tail;
    tail = head2;
    head2 = head2->right;
  }

  return head;
}

//// Sorted DLL to BST

int countNodes(Node *head) {
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->right;
  }
  return count;
}

Node *sortedDLLtoBST(Node *&head, int n) {

  if (n <= 0 || head == NULL) {
    return NULL;
  }

  Node *left = sortedDLLtoBST(head, n / 2);
  Node *root = head;
  root->left = left;

  head = head->right;

  root->right = sortedDLLtoBST(head, n - n / 2 - 1);
  return root;
}

//////

Node *mergeTwoBST(Node *root1, Node *root2) {
  Node *head1 = NULL;
  Node *head2 = NULL;

  convertBSTtoDLL(root1, head1);
  head1->left = NULL;
  convertBSTtoDLL(root2, head2);
  head2->left = NULL;

  Node *head = mergeTwoDLL(head1, head2);
  int n = countNodes(head);
  return sortedDLLtoBST(head, n);
}