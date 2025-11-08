#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
  1 base indexing
  Node  => ith index
  left child => 2*i index
  right child => 2*i + 1 index
  parent => i/2 index

  0 base indexing
  left child => 2*i + 1 index
  right child => 2*i + 2 index
*/

class Heap {
public:
  int arr[100];
  int size;

  Heap() {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val) {

    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1) {

      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void deleteFromHeap() {

    if (size == 0) {
      cout << "Nothing to delete" << endl;
      return;
    }

    // step1: put last element into first index
    arr[1] = arr[size];

    // step2: remove last element
    size--;

    // step3: take root node to its correct position
    int i = 1;
    while (i < size) {

      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex < size && arr[i] < arr[leftIndex]) {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      } else if (rightIndex < size && arr[i] < arr[rightIndex]) {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      } else {
        return;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

/// Heapify Algorithm

void heapify(int *arr, int n, int i) {

  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && arr[largest] < arr[left]) {
    largest = left;
  }

  if (right <= n && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

//// HEAP SORT ALGORITHM

void heapSort(int *arr, int n) {

  int size = n;
  while (size > 1) {
    // step1: swap
    swap(arr[size], arr[1]);
    size--;

    // step2: heapify
    heapify(arr, size, 1);
  }
}

int main() {
  Heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.print();
  h.deleteFromHeap();
  h.print();

  //// Heapify Algorithm
  int arr[6] = {-1, 54, 56, 55, 52, 50};
  int n = 5;

  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }
  cout << "Printing the array now" << endl;
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  ////// PRIORITY QUEUE
  priority_queue<int> pq; // default max heap
  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);
  cout << "element at top " << pq.top() << endl;
  pq.pop();

  /// MIN HEAP
  priority_queue<int, vector<int>, greater<int>> minheap;
  minheap.push(4);
  minheap.push(2);
  minheap.push(5);
  minheap.push(3);
  cout << "element at top " << minheap.top() << endl;
  minheap.pop();

  return 0;
}

///*****************************************************************************************

///// BUILD MIN HEAP
// 0 base indexing

void minHeapify(vector<int> &arr, int n, int i) {

  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[smallest] > arr[left]) {
    smallest = left;
  }

  if (right < n && arr[smallest] > arr[right]) {
    smallest = right;
  }

  if (smallest != i) {
    swap(arr[smallest], arr[i]);
    minHeapify(arr, n, smallest);
  }
}

vector<int> buildMinHeap(vector<int> &arr) {

  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    minHeapify(arr, n, i);
  }
}