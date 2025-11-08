#include<iostream>
#include<stack>
using namespace std;

// N STACKS IN AN ARRAY
class NStack{
  int *arr;
  int *top;
  int *next;
  
  int n,s;
  int freeSpot;
public:  
  NStack(int N,int S){
    n = N;
    s = S;
    arr = new int[s];
    top = new int[n];
    next = new int[s];

    // initilize top
    for(int i=0;i<n;i++){
      top[i] = -1;
    }

    // initilize next
    for(int i=0;i<s;i++){
      next[i] = i+1;
    }

    // update last index value to -1
    next[s-1] = -1;
    
    // initilize freeSpot
    freeSpot = 0;
  }

  bool push(int x,int m){
    // check overflow
    if(freeSpot == -1){
      cout<<"Stack Overflow"<<endl;
      return false;
    }

    // find index
    int index = freeSpot;
    
    // update freeSpot
    freeSpot = next[index];

    // insert element in array
    arr[index] = x;

    // update next
    next[index] = top[m-1];

    // update top
    top[m-1] = index;

    return true;
  }

  int pop(int m){
    // check underflow
    if(top[m-1] == -1){
      cout<<"Stack Underflow"<<endl;
      return -1;
    }

    int index = top[m-1];

    top[m-1] = next[index];

    next[index] = freeSpot;

    freeSpot = index;

    return arr[index];
  }
};

int main(){
  return 0;
}