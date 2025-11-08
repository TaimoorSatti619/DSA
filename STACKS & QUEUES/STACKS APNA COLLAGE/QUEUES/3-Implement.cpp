#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// IMPLEMENT STACK USING QUEUE
class Stack {
public:
  queue<int> q1;
  queue<int> q2;

  void push(int x) {
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    q1.push(x);

    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop() {
    int ans = q1.front();
    q1.pop();
    return ans;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};

//*********************************************************************************************

// IMPLEMENT QUEUE USING STACK

class Queue {
public:
  stack<int> s1;
  stack<int> s2;

  void push(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(x);

    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  int pop() {
    int ans = s1.top();
    s1.pop();
    return ans;
  }

  int front() { return s1.top(); }

  bool empty() { return s1.empty(); }
};

//*********************************************************************************************