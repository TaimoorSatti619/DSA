#include <iostream>
#include <queue>
using namespace std;

// IMPLEMENTATING QUEUE USING ARRAY
class Queue {
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue(int n) {
    size = n;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  // push element
  void push(int data) {
    if (rear == size) {
      cout << "Queue is full" << endl;
    } else {
      arr[rear] = data;
      rear++;
    }
  }

  // pop element
  void pop() {
    if (front == rear) {
      cout << "Queue is empty" << endl;
      return;
    } else {
      arr[front] = -1;
      front++;
      if (front == rear) {
        front = 0;
        rear = 0;
      }
    }
  }

  // get front element
  int getFront() {
    if (front == rear) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      return arr[front];
    }
  }

  // check emptiness
  bool isEmpty() {
    if (front == rear) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Queue q(10);
  q.push(5);
  q.push(15);
  q.push(25);
  q.push(35);
  cout << "front element :" << q.getFront() << endl;
  q.pop();
  cout << "front element :" << q.getFront() << endl;

  /*
    // STL queue
    queue<int> q;
    q.push(1);
    q.push(2);
    cout<<"front of queue: "<<q.front()<<endl;
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"Size of queue is: "<<q.size()<<endl;
    q.pop();
    cout<<"front of queue: "<<q.front()<<endl;
    cout<<"Size of queue is: "<<q.size()<<endl;
    if(q.empty()){
      cout<<"Queue is empty"<<endl;
    }else{
      cout<<"Queue is not empty"<<endl;
    }
  */
  return 0;
}

//**********************************************************************************************************
////////////////////// CIRCULAR QUEUE
class criculaQueue {
  int *arr;
  int front;
  int rear;
  int size;

public:
  criculaQueue(int n) {
    size = n;
    arr = new int[size];
    front = rear = -1;
  }

  // push element
  bool push(int data) {
    if ((front == 0 && rear == size - 1) ||
        (rear ==
         (front - 1) % (size - 1))) { // or if ((rear + 1) % size == front)
      cout << "Queue is full" << endl;
      return false;
    } else if (front == -1) {
      front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = data;
    return true;
  }

  // pop element
  int pop() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if (front == rear) {
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front++;
    }
    return ans;
  }

  // get front element
  int getFront() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      return arr[front];
    }
  }

  // get rear element
  int getRear() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      return arr[rear];
    }
  }

  // check emptiness
  bool isEmpty() {
    if (front == -1) {
      return true;
    } else {
      return false;
    }
  }
};

//**********************************************************************************************************

// DOUBLY ENDED QUEUE

//*************
// IMPLEMENTATING DOUBLY ENDED QUEUE USING ARRAY
class Deque {
  int *arr;
  int front;
  int rear;
  int size;

public:
  Deque(int n) {
    size = n;
    arr = new int[size];
    front = rear = -1;
  }

  // push front element
  bool pushFront(int data) {
    // check full
    if ((front == 0 && rear == size - 1) ||
        (rear ==
         (front - 1) % (size - 1))) { // or  ((rear + 1) % size == front)
      cout << "Queue is full" << endl;
      return false;
    } else if (front == -1) {
      front = rear = 0;
    } else if (front == 0 && rear != size - 1) {
      front = size - 1;
    } else {
      front--;
    }
    arr[front] = data;
    return true;
  }

  // push rear element
  bool pushRear(int data) {
    // check full
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1))) { // or ((rear + 1) % size == front)
      cout << "Queue is full" << endl;
      return false;
    } else if (front == -1) {
      front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = data;
    return true;
  }

  // pop front element
  int popFront() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if (front == rear) { // single element
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front++;
    }
    return ans;
  }

  // pop rear element
  int popRear() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int ans = arr[rear];
    arr[rear] = -1;
    if (front == rear) { // single element
      front = rear = -1;
    } else if (rear == 0) {
      rear = size - 1;
    } else {
      rear--;
    }
    return ans;
  }

  // get front element
  int getFront() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return arr[front];
  }

  // get rear element
  int getRear() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return arr[rear];
  }

  // check emptiness
  bool isEmpty() {
    if (front == -1) {
      return true;
    } else {
      return false;
    }
  }

  // check fullness
  bool isFull() {
    if ((front == 0 && rear == size - 1) ||
        (front != 0 && rear == (front - 1) % (size - 1))) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {

  /*
  // STL
  deque<int> d;
  d.push_back(1);
  d.push_front(2);
  cout << d.front() << endl;
  cout << d.back() << endl;
  d.pop_back();
  cout << d.back() << endl;
  d.pop_front();
  cout << d.front() << endl;
  if (d.empty()){
    cout << "Deque is empty" << endl;
  }
  else{
    cout << "Deque is not empty" << endl;
  }
  */
  return 0;
}
