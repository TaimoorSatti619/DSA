#include<iostream>
#include<stack>
#include<vector>
using namespace std;


/////////// THE CELEBRITY PROBLEM

int celebrity(vector<vector<int>> &M){
  int n = M.size();
  stack<int> s;
  
  // step 1=> push all elements into stack
  for(int i=0; i<n; i++){
    s.push(i);
  }

  // step 2=> get two elements and compare them
  while(s.size() > 1){
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if(M[a][b] == 1){
      s.push(b);
    }else{
      s.push(a);
    }
  }
  
  int ans = s.top();
  
  // step 3=> check if the remaining element is a cele
  /*int zeroCnt = 0;
  for(int i=0; i<n; i++){
    if(M[ans][i] == 0){
      zeroCnt++;
    }
  }

  if(zeroCnt != n){
    return -1;
  }

  int oneCnt = 0;
  for(int i=0; i<n; i++){
    if(M[i][ans] == 1){
      oneCnt++;
    }
  }
  
  if(oneCnt != n-1){
    return -1;
  }

  return ans;
*/
  
  // or we can write step 3 as
  for(int i = 0; i<n;i++){
    if(i == ans){
      continue;
    }
    if(M[ans][i] == 1 || M[i][ans] == 0){
      return -1;
    }
  }
  return ans;
  
}

//********************************************************************************************************

//////// MAX RECTANGULAR AREA IN A MATRIX

vector<int> nextSmaller(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

vector<int> prevSmaller(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

int largestRectangleArea(vector<int> arr, int n) {
  vector<int> next(n);
  next = nextSmaller(arr, n);

  vector<int> prev(n);
  prev = prevSmaller(arr, n);

  int area = INT_MIN;
  for (int i = 0; i < n; i++) {
    int l = arr[i];
    if (next[i] == -1) {
      next[i] = n;
    }
    int b = next[i] - prev[i] - 1;
    int newArea = l * b;
    area = max(area, newArea);
  }
  return area;
}

//----------------------------------------------------
int maxRectangularArea(vector<vector<int>> &M){
  int n = M.size();
  int m = M[0].size();

  // area for first row
  int area = largestRectangleArea(M[0], m);

  for(int i=1; i<n; i++){
    for(int j=0; j<m; j++){
      if(M[i][j] != 0){
        M[i][j] = M[i][j] +  M[i-1][j];
      }
      else{
        M[i][j] = 0;
      }
    }
    area = max(area, largestRectangleArea(M[i], m));
  }
  return area; 
}

//********************************************************************************************************
