#include <iostream>
#include <stack> // LIFO   last in first out
using namespace std;
/*
// Stack implementation
class Stack {
public:
  // properties
  int *arr;
  int size;
  int top;

  // behaviour

  Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  // push operation
  void push(int element) {
    if (size - top > 1) {
      top++;
      arr[top] = element;
    } else {
      cout << "Stack overflow" << endl;
    }
  }

  // pop operation
  void pop() {
    if (top >= 0) {
      top--;
    } else {
      cout << "Stack underflow" << endl;
    }
  }

  // peek operation
  int peek() {
    if (top >= 0) {
      return arr[top];
    } else {
      cout << "Stack is empty" << endl;
      return -1;
    }
  }

  // isEmpty operation
  bool isEmpty() {
    if (top == -1) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {

  Stack st(5);

  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;

  if (st.isEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }





  
    // STL stack
    stack<int> s; // stack of integers

    // push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // pop elements from the stack
    s.pop();

    cout<<"Printing top element "<<s.top()<<endl;

    if(s.empty()){
      cout<<"Stack is empty"<<endl;
    }
    else{
      cout<<"Stack is not empty"<<endl;
    }

    cout<<"Size of stack is "<<s.size()<<endl;

  return 0;
}

*/

//***********************************************************************************************************

//////////// TWO STACK IN ONE ARRAY //////
class twoStacks{
public:
  int* arr;
  int size;
  int top1;
  int top2;

  twoStacks(int size){
    this->size = size;
    arr = new int[size];
    top1 = -1;
    top2 = size;
  }

  // push element in stack1
  void push1(int element){
    if(top2 - top1 > 1){
      top1++;
      arr[top1] = element;
    }
  }

  // push element in stack2
  void push2(int element){
    if(top2 - top1 > 1){
      top2--;
      arr[top2] = element;
    }
  }

  // pop element from stack1
  int pop1(){
    if(top1 >= 0){
      int ans = arr[top1];
      top1--;
      return ans;
    }
    else{
      return -1;
    }
  }

  // pop element from stack2
  int pop2(){
    if(top2 < size){
      int ans = arr[top2];
      top2++;
      return ans;
    }
    else{
      return -1;
    }
  }
};

//***************************************************************************************************************** */

///////////// STACK IMPLEMENTATION USING LINKLIST
class Node{
  public:
    int data;
    Node* next;

    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

class Stack{
  public:
    Node* head;
    Node* tail;

    Stack(){
      head = tail = NULL;
    }


    /// push
    void push(int x){
      Node* temp = new Node(x);
      if(head == NULL){
        head = tail = temp;
      }
      else{
        tail->next = temp;
        tail = temp;
      }
    }


    // pop
    void pop(){
      if(head == NULL){
        cout<<"stack is empty"<<endl;
      }
      else{

        if(head == tail){
          head = tail = NULL;
          return;
        }

        Node* curr = head;
        while(curr->next != tail){
          curr = curr->next;
        }

        curr->next = NULL;
        tail = curr;

      }
    }


    // top
    int top(){
      if(head == NULL){
        return -1;
      }
      else{
        return tail->data;
      }
    }


    // empty
    bool empty(){
      if(head == NULL){
        return true;
      }
      else{
        return false;
      }
    }
};

