#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    //constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class List{
  Node* head;
  Node* tail;

public:
  List(){
    head = tail = NULL;
  }

  // insert at head
  void push_front(int val){ // O(1)
    Node* newnode = new Node(val);  // dynamicaly creating a node
    if(head == NULL){
      head = tail = newnode;
    }
    else{
      newnode->next = head;
      head = newnode;
    }
  }

  // insert at tail
  void push_back(int val){ // O(1)
    Node* newnode = new Node(val);
    if(head == NULL){
      head = tail = newnode;
    }
    else{
      tail->next = newnode;
      tail = newnode;
    }
  }

  // delete first node at head
  void pop_front(){ // O(1)
    if(head == NULL){
      cout<<"List is empty"<<endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;

    delete temp;
  }

  // delete last node at tail
  void pop_back(){ // O(n)
    if(head == NULL){
      cout<<"List is empty"<<endl;
      return;
    }
    Node* temp = head;
    while(temp->next != tail){
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
  }

  // insert at middle
  void insert(int pos, int val){ // O(n)
    if(pos < 0){
      cout<<"Invalid position"<<endl;
      return;
    }
    if(pos == 0){
      push_front(val);
      return;
    }
    
    Node* temp = head;
    for(int i = 0; i < pos-1; i++){
      if(temp == NULL){
        cout<<"Invalid position"<<endl;
        return;
      }
      temp = temp->next;
    }
    
    Node* newnode = new Node(val);
    newnode->next = temp->next;
    temp->next = newnode;
  }

  // search in list
  void search(int key){ // O(n)         // int search
    Node* temp = head;
    for(int i = 0; temp != NULL; i++){
      if(temp->data == key){
        cout<<"Element found at position "<<i<<endl;   // return i
        return;
      }
      temp = temp->next;
    }
    cout<<"Element not found"<<endl;         // return -1
  }

  //print
  void print(){ // O(n)
    Node* temp = head;
    while(temp != NULL){
      cout<<temp->data<<"->";
      temp = temp->next;
    }
    cout<<"NULL"<<endl;
  }

};

int main(){
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);

  ll.push_back(5);
  ll.push_back(6);
  ll.push_back(7);
  ll.print();
  
  ll.insert(3,4);
  ll.print();
  ll.search(7);
  return 0;
}