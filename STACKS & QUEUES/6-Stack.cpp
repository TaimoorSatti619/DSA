#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;

// DESIGN A STACK THAT SUPPORTS GET MIN
class MinStack {
  stack<int> s;
  int mini;

public:
  MinStack() {
    mini = INT_MAX;
  }

  // push
  void push(int x) {
    if (s.empty()) {
      s.push(x);
      mini = x;
    } else {
      if (x < mini) {
        s.push(2 * x - mini);
        mini = x;
      } else {
        s.push(x);
      }
    }
  }

  // pop element
  int pop() {
    if (s.empty()) {
      return -1;
    }
    int curr = s.top();
    s.pop();
    if (curr > mini) {
      return curr;
    } else {
      int prevMini = mini;
      mini = 2 * mini - curr;
      return prevMini;
    }
  }

    /*
      void pop(){
        if(s.empty()){
          return;
        }
        int curr = s.top();
        s.pop();
        if(curr < mini){
          mini = 2*mini - curr;
        }

        if(s.empty()){
          mini = INT_MAX;
        }
      }*/

    // top element
    int top() {
      if (s.empty()) {
        return -1;
      }
      int curr = s.top();
      if (curr < mini) {
        return mini;
      } else {
        return curr;
      }
    }

    // get min
    int getMin() {
      if (s.empty()) {
        return -1;
      }
      return mini;
    }
  };

  int main() {
    return 0; 
  }