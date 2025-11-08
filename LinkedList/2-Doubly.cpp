#include <iostream>
using namespace std; 
                      // Node=>  a data and next and previous node address
// Node created
class Node{
  public:
    int data;
    Node* next;
    Node* prev;

// constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
// destructor
  ~Node(){
    int val = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    } 
    cout<<"Memory is free for node with data "<<val<<endl;
  }
};




// inserstion at head
void insertAtHead(Node* &head,Node* &tail, int d){
  if(head == NULL){
    Node* temp = new Node(d);
    head = temp;  
    tail = temp; 
  }
  else{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

// insertion at tail
void insertAtTail(Node* &head,Node* &tail, int d){
  if(tail == NULL){
    Node* temp = new Node(d);
    head = temp;  
    tail = temp; 
  }
  else{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

// insertion at position
void insertAtPosition(Node* &head,Node* &tail,int position , int d){

  if(position == 1){  // inserting at first position
    insertAtHead(head,tail,d);  
    return;
  }

  Node* temp = head;
  int cnt = 1;
  while(cnt < position-1){
    temp = temp->next;
    cnt++;
  }

  // inserting at last position
  if(temp->next == NULL){
    insertAtTail(head,tail,d);
    return;
  }

  Node* nodeToInsert = new Node(d);
  nodeToInsert->next = temp->next;
  temp->next->prev = nodeToInsert;
  temp->next = nodeToInsert;
  nodeToInsert->prev = temp;
}

// deleting  node at position
void deleteNode(Node* &head,int position){
  if(position == 1){
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else{
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < position){
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;   
  }
}



//printing Node
void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}
// printing length
int printLen(Node* &head){
  Node* temp = head;
  int len = 0;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }
  return len;
}


int main(){
  Node* node1 = new Node(10);
  Node* head = node1;
  Node* tail = node1;


  print(head);

  insertAtHead(head,tail,12);
  print(head);

  insertAtTail(head,tail,15);
  print(head);


  insertAtPosition(head,tail,2,20);
  print(head);

  insertAtPosition(head,tail,1,40);
  print(head);

  insertAtPosition(head,tail,6,30);
  print(head);

  insertAtPosition(head,tail,7,40);
  print(head);

  deleteNode(head,7);
  print(head);
  cout<<"Head : "<<head->data<<endl;
  cout<< "Tail : "<<tail->data<<endl;

  
  cout<<"Length : "<<printLen(head)<<endl;
  return 0;
}