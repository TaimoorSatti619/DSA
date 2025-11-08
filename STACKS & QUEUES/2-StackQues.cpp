#include <iostream>
#include <stack> // LIFO
using namespace std;

int main() {

  ///////////////////////REVERSE A STRING USING STACK
  string str = "alien";
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    s.push(ch);
  }
  string ans = "";
  while (!s.empty()) {
    char ch = s.top();
    ans.push_back(ch);
    s.pop();
  }
  cout << ans << endl;

  //***********************************************************************************************************
  return 0;
}

//***********************************************************************************************************
/////////////////////// DELETE MIDDLE ELEMENT OF STACK

void solve(stack<int> &s, int count, int size) {
  // base case
  if (count == size / 2) {
    s.pop();
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  solve(s, count + 1, size);
  // backtrack
  s.push(num);
}
void deleteMid(stack<int> &s, int size) {
  int cnt = 0;
  solve(s, cnt, size);
}

//***********************************************************************************************************

/////////////////////// VALID PARAENTHESIS ///////////imp question/////////////
bool isValid(string str) {
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    // if opening stack push
    // if closing stacktop check and pop
    if (ch == '(' || ch == '{' || ch == '[') {
      s.push(ch);
    } else {
      // for closing bracket
      if (!s.empty()) {
        char top = s.top();
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
            (ch == ']' && top == '[')) {
          s.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  if (s.empty()) {
    return true;
  } else {
    return false;
  }
}

//***********************************************************************************************************

/////////////////////// INSERT AN ELEMENT AT THE BOTTOM OF STACK///////////////////////////

void solve(stack<int> &s, int x) {
  // base case
  if (s.empty()) {
    s.push(x);
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  solve(s, x);
  // backtrack
  s.push(num);
}
stack<int> insertAtBottom(stack<int> &s, int x) {
  solve(s, x);
  return s;
}

//***********************************************************************************************************

/////////////////////////REVERSE A STACK ///////////////////////////////////////

void insertAtBottom1(stack<int> &s, int x) {
  // base case
  if (s.empty()) {
    s.push(x);
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  insertAtBottom1(s, x);

  // backtrack
  s.push(num);
}

void reverse(stack<int> &s) {
  // base case
  if (s.empty()) {
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  reverse(s);
  // backtrack
  insertAtBottom1(s, num);
}

//***********************************************************************************************************

////////////////////////// SORT A STACK/////////////////////////////////////////////////////

void sortInsert(stack<int> &s, int x) {
  // base case
  if (s.empty() || (!s.empty() && s.top() < x)) {
    s.push(x);
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  sortInsert(s, x);

  // backtrack
  s.push(num);
}

void sortStack(stack<int> &s) {
  // base case
  if (s.empty()) {
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  sortStack(s);

  // backtrack
  sortInsert(s, num);
}

//***********************************************************************************************************

/////////////////////////REDUNDANT BRACKETS///////////////////////////////////////////

bool redundantBrackets(string str) {
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      s.push(ch);
    } else {
      if (ch == ')') {
        bool redundant = true;
        while (s.top() != '(') {
          char top = s.top();
          if (top == '+' || top == '-' || top == '*' || top == '/') {
            redundant = false;
          }
          s.pop();
        }
        if (redundant == true) {
          return true;
        }
        s.pop();
      }
    }
  }
  return false;
}

//***********************************************************************************************************

/////////////////////////MINUMUM COST TO MAKE STRING VALID /////

int findMinCost(string str) {
  // odd condition
  if (str.length() % 2 != 0) {
    return -1;
  }

  stack<char> s;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (ch == '{') {
      s.push(ch);
    } else {
      // ch is closing brace
      if (!s.empty() && s.top() == '{') {
        s.pop();
      } else {
        s.push(ch);
      }
    }
  }

  // stack contains invalid expressions
  int a = 0;
  int b = 0;
  while (!s.empty()) {
    if (s.top() == '{') {
      b++;
    } else {
      a++;
    }
    s.pop();
  }
  int ans = (a + 1) / 2 + (b + 1) / 2;
  return ans;
}

//***********************************************************************************************************
