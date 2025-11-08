#include<iostream>
#include<queue>
using namespace std;

// link list
class Node{
public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

//*************************************************************************************************

/// QUEUE IMPLEMENTATION USING LINK LIST
class Queue{
  Node* head;
  Node* tail;

  public:

  Queue(){
    head = tail = NULL;
  }

  // insert data
  void push(int data){
    Node* newNode = new Node(data);
    if(empty()){
      head = tail = newNode;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
  }

  // delete data
  void pop(){
    if(empty()){
      cout<<"Queue is empty"<<endl;
      return;
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  // get front data
  int front(){
    if(empty()){
      cout<<"Queue is empty"<<endl;
      return -1;
    }
    
    return head->data;
  }

  bool empty(){
    return head == NULL;
  }
};


int main(){
  queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
  return 0;
}