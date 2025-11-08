#include<iostream>
#include<queue>
using namespace std;

class circularQueue{
  int * arr;
  int f;
  int r;
  int cap;
  int currSize;
  public:
  circularQueue(int size){
    arr = new int[size];
    cap = size;
    currSize = 0;
    f = 0;
    r = -1;   
  }
  
  void push(int data){
    if(currSize == cap){
      cout<<"Queue is full"<<endl;
      return;
    }
    
    r = (r+1)%cap;
    arr[r] = data;
    currSize++;
  }
  
  void pop(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return;
    }
    f = (f+1)%cap;
    currSize--;
  }

  int getFront(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return -1;
    }

    return arr[f];
  }

  bool isEmpty(){
    return currSize == 0;
  }

};

int main(){
  circularQueue q(3);
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  q.push(4);

  while(!q.isEmpty()){
    cout<<q.getFront()<<" ";
    q.pop();
  }
  return 0;
}