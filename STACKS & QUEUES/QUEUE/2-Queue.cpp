#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

//////// QUEUE REVERSAL
queue<int> reverseQueue(queue<int> &q) {
  stack<int> s;
  while (!q.empty()) {
    int element = q.front();
    q.pop();
    s.push(element);
  }
  while (!s.empty()) {
    int element = s.top();
    s.pop();
    q.push(element);
  }
  return q;
}

// using recurrsion
queue<int> reverseQueue1(queue<int> &q) {
  queue<int> ans;
  if (q.empty()) {
    return ans;
  }
  int element = q.front();
  q.pop();
  // recursive call
  ans = reverseQueue(q);
  ans.push(element);
  return ans;
}

//**************************************************************************************

////// FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K

vector<int> firstNegativeInWindow(vector<int> &arr, int n, int k) {
  deque<int> dq;
  vector<int> ans;

  // process first window of size k
  for (int i = 0; i < k; i++) {
    if (arr[i] < 0) {
      dq.push_back(i);
    }
  }

  // store ans of first k size window
  if (dq.size() > 0) {
    ans.push_back(arr[dq.front()]);
  } else {
    ans.push_back(0);
  }

  // process for remaining windows
  for (int i = k; i < n; i++) {
    // removal
    if (!dq.empty() && (i - dq.front()) >= k) {
      dq.pop_front();
    }

    // addition
    if (arr[i] < 0) {
      dq.push_back(i);
    }

    // ans store
    if (dq.size() > 0) {
      ans.push_back(arr[dq.front()]);
    } else {
      ans.push_back(0);
    }
  }
  return ans;
}

//**************************************************************************************

///// REVERSE FIRST K ELEMENTS OF QUEUE
queue<int> reverseFirstK(queue<int> q, int k) {
  stack<int> s;

  // step 1: push first k elements in stack
  for (int i = 0; i < k; i++) {
    int val = q.front();
    q.pop();
    s.push(val);
  }

  // step 2: push stack elements in queue
  while (!s.empty()) {
    int val = s.top();
    s.pop();
    q.push(val);
  }

  // step 3: push n-k elements in queue
  int t = q.size() - k;
  while (t--) {
    int val = q.front();
    q.pop();
    q.push(val);
  }
  return q;
}

//**************************************************************************************

///// STREAM FIRST NON REPEATING CHARACTER
string firstNonRepeating(string s) {
  unordered_map<char, int> cnt;
  queue<int> q;
  string ans = "";

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    // increase cnt
    cnt[ch]++;

    // push  in queue
    q.push(ch);

    while (!q.empty()) {
      if (cnt[q.front()] > 1) {
        // repeating ha
        q.pop();
      } else {
        // non repeating ha
        ans.push_back(q.front());
        break;
      }
    }
    if (q.empty()) {
      ans.push_back('#');
    }
  }
  return ans;
}

//**************************************************************************************

////// GAS STATION  or  CICULAR TOUR
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int n = gas.size();
  int start = 0;
  int kami = 0;
  int balance = 0;
  for (int i = 0; i < n; i++) {
    balance += gas[i] - cost[i];
    if (balance < 0) {
      start = i + 1;
      kami += balance;
      balance = 0;
    }
  }
  if (kami + balance >= 0) {
    return start;
  } else {
    return -1;
  }
}

//**************************************************************************************

////// INTERLEAVE THE FIRST HALF OF THE QUEUE WITH THE SECOND HALF

// Using Queue
vector<int> rearrangetheQueue(queue<int> &q) {
  vector<int> ans;
  queue<int> newQ;
  int n = q.size() / 2;

  for (int i = 0; i < n; i++) {
    int val = q.front();
    q.pop();
    newQ.push(val);
  }

  while (!newQ.empty()) {
    ans.push_back(newQ.front());
    newQ.pop();
    ans.push_back(q.front());
    q.pop();
  }
  return ans;
}

//// USING STACK
vector<int> rearrangetheQueue1(queue<int> &q) {
  vector<int> ans;
  stack<int> s;
  int n = q.size() / 2;

  // stack ma push karo half elements
  for (int i = 0; i < n; i++) {
    int val = q.front();
    q.pop();
    s.push(val);
  } // queue:16 17 18 19 20,  stack: 15 14 13 12 11

  // stack sey wapis queue ma dalo
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  } // queue: 16 17 18 19 20 15 14 13 12 11

  // queue kay front sey nikal kar back ma dalo
  for (int i = 0; i < n; i++) {
    q.push(q.front());
    q.pop();
  } // queue: 15 14 13 12 11 16 17 18 19 20

  // ab wapis stack ma dalo
  for (int i = 0; i < n; i++) {
    s.push(q.front());
    q.pop();
  } // queue: 16 17 18 19 20,   stack: 11 12 13 14 15

  // ab ans ma stack aur queue sey push karo
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
    ans.push_back(q.front());
    q.pop();
  } // queue: 11 16 12 17 13 18 14 19 15 20

  return ans;
}

//**************************************************************************************

///// K QUEUES IN A SINGLE ARRAY

class KQueues {
  int n;
  int k;
  int *arr;
  int freeSpot;
  int *front;
  int *rear;
  int *next;

public:
  KQueues(int n, int k) {
    this->n = n;
    this->k = k;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    for (int i = 0; i < k; i++) {
      front[i] = -1;
      rear[i] = -1;
    }
    next = new int[n];
    for (int i = 0; i < n; i++) {
      next[i] = i + 1;
    }
    next[n - 1] = -1;
    freeSpot = 0;
  }

  // push element in queue
  void enqueue(int data, int qn) {
    // over flow
    if (freeSpot == -1) {
      cout << "No empty space is present" << endl;
      return;
    }

    // find first free index
    int index = freeSpot;

    // update freeSpot
    freeSpot = next[index];

    // check whether first element
    if (front[qn - 1] == -1) {
      front[qn - 1] = index;
    } else {
      // link new element to the prev element
      next[rear[qn - 1]] = index;
    }

    // update next
    next[index] = -1;

    // update rear
    rear[qn - 1] = index;

    // push element
    arr[index] = data;
  }

  // pop element from queue
  int dequeue(int qn) {
    // underflow
    if (front[qn - 1] == -1) {
      cout << "Queue is empty" << endl;
      return -1;
    }

    // find index to pop
    int index = front[qn - 1];

    // font ko agey barhaho
    front[qn - 1] = next[index];

    // free slot ko manage karo
    next[index] = freeSpot;
    freeSpot = index;
    return arr[index];
  }
};

//**************************************************************************************

//// SUM OF MAX AND MIN ELEMENTS IN WINDOW OF SIZE K
int sumOfMaxAndMin(int *arr, int n, int k) {
  deque<int> maxi(k);
  deque<int> mini(k);

  // addition of first k elements
  for (int i = 0; i < k; i++) {

    while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
      maxi.pop_back();
    }

    while (!mini.empty() && arr[mini.back()] >= arr[i]) {
      mini.pop_back();
    }

    maxi.push_back(i);
    mini.push_back(i);
  }

  int ans = 0;
  for (int i = k; i < n; i++) {

    ans = ans + arr[maxi.front()] + arr[mini.front()];

    // next window

    // removal
    while (!maxi.empty() && i - maxi.front() >= k) {
      maxi.pop_front();
    }

    while (!mini.empty() && i - mini.front() >= k) {
      mini.pop_front();
    }

    // addition
    while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
      maxi.pop_back();
    }

    while (!mini.empty() && arr[mini.back()] >= arr[i]) {
      mini.pop_back();
    }

    maxi.push_back(i);
    mini.push_back(i);
  }

  // make sure to consider last wali window
  ans = ans + arr[maxi.front()] + arr[mini.front()];
  return ans;
}

//**************************************************************************************
