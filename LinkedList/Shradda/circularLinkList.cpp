#include <iostream>
using namespace std;

// circular linklist
class Node{
public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};
class circularList{
  Node* head;
  Node* tail;
public:
  circularList(){
    head = tail = NULL;
  }

  // insert at head
  void insertAtHead(int data){
    Node* newNode = new Node(data);
    if(tail == NULL){
      head = tail = newNode;
      tail->next = head;
    }
    else{
      newNode->next = head;
      head = newNode;
      tail->next = head;
    }
  }

  // insert at tail
  void insertAtTail(int data){
    Node* newNode = new Node(data);
    if(tail == NULL){
      head = tail = newNode;
      tail->next = head;
    }
    else{
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }

  // delete at head
  void deleteAtHead(){
    if(head == NULL){
      cout << "List is empty" << endl;
      return;
    }
    else if(head == tail){
      delete head;
      head = tail = NULL;
    }
    else{
      Node* temp = head;
      head = head->next;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }  
  }

  // delete at tail
  void deleteAtTail(){
    if(head == NULL){
      cout << "List is empty" << endl;
      return;
    }
    else if(head == tail){
      delete tail;
      head = tail = NULL;
    }
    else{
      Node* temp = tail;
      Node* prev = head;
      while(prev->next != tail){
        prev = prev->next;
      }
      tail = prev;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
  }

  // print 
  void print(){
    if(head == NULL){
      cout<<"List is empty"<<endl;
    }
    Node* temp = head->next;
    cout<<head->data<<"->";
    
    while(temp != head){
      cout<<temp->data<<"->";
      temp = temp->next;
    }
    
    cout<<temp->data<<endl;   
  }

};

int main(){
  circularList cll;
  cll.insertAtHead(10);
  cll.insertAtHead(20);
  cll.insertAtHead(30);
  cll.print();
  cll.insertAtTail(40);
  cll.insertAtTail(50);
  cll.print();
  cll.deleteAtHead();
  cll.print();
  cll.deleteAtTail();
  cll.print();
  
  
  return 0;
}