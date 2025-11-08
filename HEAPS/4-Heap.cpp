#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Question 1 =>  Smallest range in K lists

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

vector<int> findSmallestRange(vector<vector<int>> &arr) {

  int k = arr.size();
  int mini = INT_MAX, maxi = INT_MIN;
  priority_queue<node *, vector<node *>, compare> minHeap;

  for (int i = 0; i < k; i++) {
    int element = arr[i][0];
    mini = min(mini, element);
    maxi = max(maxi, element);
    minHeap.push(new node(arr[i][0], i, 0));
  }

  int start = mini, end = maxi;

  while (!minHeap.empty()) {

    node *temp = minHeap.top();
    minHeap.pop();

    mini = temp->data;

    if (maxi - mini < end - start) {
      start = mini;
      end = maxi;
    }

    int i = temp->row;
    int j = temp->col;

    if (j + 1 < arr[i].size()) {
      maxi = max(maxi, arr[i][j + 1]);
      minHeap.push(new node(arr[i][j + 1], i, j + 1));
    } else {
      break;
    }
  }
  return {start, end};
}

///*************************************************************************************************

/// Question 2 =>  Median in a stream of running integers

int sigNum(int left, int right) {
  if (left == right) {
    return 0;
  } else if (left > right) {
    return 1;
  } else {
    return -1;
  }
}

void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini,
                double &median) {

  switch (sigNum(maxi.size(), mini.size())) {

  case 0:
    if (element > median) {
      mini.push(element);
      median = mini.top();
    } else {
      maxi.push(element);
      median = maxi.top();
    }
    break;

  case 1:
    if (element > median) {
      mini.push(element);
      median = (maxi.top() + mini.top()) / 2.0;
    } else {
      mini.push(maxi.top());
      maxi.pop();
      maxi.push(element);
      median = (maxi.top() + mini.top()) / 2.0;
    }
    break;

  case -1:
    if (element > median) {
      maxi.push(mini.top());
      mini.pop();
      mini.push(element);
      median = (maxi.top() + mini.top()) / 2.0;
    } else {
      maxi.push(element);
      median = (maxi.top() + mini.top()) / 2.0;
    }
    break;
  }
}

vector<double> findMedian(vector<int> &arr, int n) {

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  vector<double> ans;

  double median = 0;
  for (int i = 0; i < n; i++) {
    callMedian(arr[i], maxHeap, minHeap, median);
    ans.push_back(median);
  }

  return ans;
}
