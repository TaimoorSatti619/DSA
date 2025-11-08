#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// Question 1 =>  Kth Largest Sum Subarray

int kthLargestSum(int arr[], int n, int k) {
  priority_queue<int, vector<int>, greater<int>> minheap;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (minheap.size() < k) {
        minheap.push(sum);
      } else {
        if (sum > minheap.top()) {
          minheap.pop();
          minheap.push(sum);
        }
      }
    }
  }

  return minheap.top();
}

///*********************************************************************************

// Question 2 =>  Merge K sorted arrays
class node {
public:
  int data;
  int row;
  int col;

  node(int d, int r, int c) {
    data = d;
    row = r;
    col = c;
  }
};

class compare {
public:
  bool operator()(node *a, node *b) { return a->data > b->data; }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {

  priority_queue<node *, vector<node *>, compare> pq;

  for (int i = 0; i < k; i++) {
    node *temp = new node(kArrays[i][0], i, 0);
    pq.push(temp);
  }

  vector<int> ans;

  while (!pq.empty()) {
    node *temp = pq.top();
    pq.pop();
    ans.push_back(temp->data);

    int row = temp->row;
    int col = temp->col;

    if (col + 1 < kArrays[row].size()) {
      node *next = new node(kArrays[row][col + 1], row, col + 1);
      pq.push(next);
    }
  }

  return ans;
}

////*********************************************************************************

// Question 3 =>  Merge k sorted linked lists

class Node {
public:
  int data;
  Node *next;

  Node(int d) {
    data = d;
    next = NULL;
  }
};

class Compare {
public:
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

Node *mergeKSortedLists(vector<Node *> &Lists) {

  priority_queue<Node *, vector<Node *>, Compare> pq;

  int k = Lists.size();

  if (k == 0) {
    return NULL;
  }

  for (int i = 0; i < k; i++) {
    if (Lists[i] != NULL) {
      pq.push(Lists[i]);
    }
  }

  Node *head = NULL;
  Node *tail = NULL;

  while (!pq.empty()) {

    Node *top = pq.top();
    pq.pop();

    if (top->next != NULL) {
      pq.push(top->next);
    }

    if (head == NULL) {
      head = top;
      tail = top;
    } else {
      tail->next = top;
      tail = top;
    }
  }

  return head;
}