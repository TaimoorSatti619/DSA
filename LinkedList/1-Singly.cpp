#include <iostream>
using namespace std;       /* linked list => is a collection of Nodes            
                              Nodes =>   a data and next node address */                            
// Node created
class Node{
  public:
    int data;
    Node* next;

// construtor
    Node(int data){
      this->data = data;
      this->next = NULL;
    }

// destructor
    ~Node(){
      int value = this->data;
      // memory free
      if(this->next != NULL){
        delete next;
        this->next = NULL;
      }
      cout<<"Memory is free for node with data "<<value<<endl;
    }
};



// inserstion at head
void insertAtHead(Node* &head,Node* &tail, int d){
  if(head == NULL){
      //new Node
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
  }
  else{
    //new Node
    Node* temp = new Node(d);  
    temp->next = head;
    head = temp;
  }
}




// insertion at tail
void insertAtTail(Node*&head,Node* &tail, int d){
  if(tail == NULL){
      //new Node
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
  }
  else{
    //new Node
    Node* temp = new Node(d);
    tail->next = temp;
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
  temp->next = nodeToInsert; 
}



// deleting node at position
void deleteNode(Node* &head, int position){
  //deleting first or start node
  if(position == 1){            //   if value is given then=> if(head->data == val)...
    Node* temp = head;
    head = head->next;
    // memeory free
    temp->next = NULL;
    delete temp;
  }
  else{
    //deleting any middle node or last node
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < position){           //   if value is given then=> while(curr->data != val)...
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    prev->next = curr->next;
    // memeory free
    curr->next = NULL;
    delete curr;   
  }
}




// printing the linked list
void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}


int main(){

  Node* node1 = new Node(19);  
  // cout<<node1->data<<endl;
  // cout<<node1->next<<endl;

  // head pointed to node1
  Node* head = node1;
  // print(head);
  // insertAtHead(head,tail, 12);
  // print(head);
  // insertAtHead(head,tail,6);
  // print(head);

// tail pointed to node1
  Node* tail = node1;
  print(head);
  insertAtTail(head,tail, 12);
  print(head);
  insertAtTail(head,tail,6);
  print(head);

  insertAtPosition(head,tail,3,10);
  print(head);

  insertAtPosition(head,tail,1,17);
  print(head);

  insertAtPosition(head,tail,6,20);
  print(head);

  cout<<"HEAD : "<<head->data<<endl;
  cout<<"TAIL : "<<tail->data<<endl;


  deleteNode(head,6);
  print(head);
  
  
  return 0;
}
