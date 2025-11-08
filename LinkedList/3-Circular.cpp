#include <iostream>
using namespace std; 
    // singly case
class Node{
  public:
    int data;
    Node* next;

    //constructor
    Node(int data){
      this->data = data;
      this->next = NULL;
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

// inserstion 
void insertNode(Node* &tail,int element,int d){
  // empty list
  if(tail == NULL){
    Node* temp = new Node(d);
    tail = temp;
    temp->next = temp;
  }
  else{
    // non-empty list
    // assuming that the element is present in the list
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }
    // elemtnt found -> curr is representing element wala node
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;  
  }
}

// deletation
void deleteNode(Node* &tail,int value){
  // empty list
  if(tail == NULL){
    cout<<"List is empty, please check again"<<endl;
  }
  else{
    // non-empty list
    // assuming that the value is present in the list
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    // 1 node linked list
    if(curr == prev){
      tail = NULL;
    }
    // >=2 node linked list
    else if(tail == curr){
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}


//printing linklist
void print(Node* &tail){
  Node* temp = tail;
  // empty list
  if(tail == NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  do{
    cout<<temp->data<<" ";
    temp = temp->next;
  }while(temp != tail);
  cout<<endl;
}

int main(){

  Node* tail = NULL;

  insertNode(tail,3,5);
  print(tail);
  
  insertNode(tail,5,6);
  print(tail);
  
  insertNode(tail,6,9);
  print(tail);

  insertNode(tail,9,10);
  print(tail);

  insertNode(tail,6,8);
  print(tail);

  insertNode(tail,6,7);
  print(tail);

  deleteNode(tail,10);
  print(tail);

  return 0;
}



/*


// doubly case
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

// inserstion
void insertNode(Node* &tail,int element,int d){
  // empty list
  if(tail == NULL){
    Node* temp = new Node(d);
    tail = temp;
    temp->next = temp;
    temp->prev = temp;
  }
  else{
    // non-empty list
    // assuming that the element is present in the list
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
  }
}


// deletation
void deleteNode(Node* &tail,int value){
  // empty list
  if(tail == NULL){
    cout<<"List is empty, please check again"<<endl;
  }
  else{
    // non-empty list
    // assuming that the value is present in the list
    Node* previ = tail;
    Node* curr = previ->next;
    while(curr->data != value){
      previ = curr;
      curr = curr->next;
    }
    previ->next = curr->next;
    if(curr == previ){
      tail = NULL;
    }
    else if(tail == curr){
      tail = previ;
    }
    curr->next->prev = previ;
    curr->next = NULL;
    delete curr;
  }
}

// printing linklist
void print(Node* &tail){
  Node* temp = tail;
  // empty list
  if(tail == NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  do{
    cout<<temp->data<<" ";
    temp = temp->next;
  }while(temp != tail);
  cout<<endl;
}


int main(){
  Node* tail = NULL;
  
  insertNode(tail,3,5);
  print(tail);

  insertNode(tail,5,6);
  print(tail);

  insertNode(tail,6,8);
  print(tail);
  
  insertNode(tail,8,10);
  print(tail);

  insertNode(tail,6,7);
  print(tail);

  insertNode(tail,8,9);
  print(tail);


  deleteNode(tail,5);
  print(tail);


  return 0;
}


*/