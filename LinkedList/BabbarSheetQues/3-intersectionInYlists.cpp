#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

///// APPROCH 1 =>    USING FLOYD CYCLE DETECTION ALGORITHM

Node* getIntersectionNode(Node* head1, Node* head2){

  Node* last = head1;
  while(last->next != NULL){
    last = last->next;
  }
  last->next = head2;

  Node* slow = head1;
  Node* fast = head1;
  While(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      break;
    }
  }

  slow = head1;
  while(slow != fast){
    slow = slow->next;
    fast = fast->next;
  }

  last->next = NULL;

  return fast;
  
}


// APPROCH 2 

Node* getIntersectionNode(Node* head1, Node* head2){
  Node* ptr1 = head1;
  Node* ptr2 = head2;

  while(ptr1 != ptr2){
    
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;

    if(ptr1 == NULL){
      ptr1 = head2;
    }
    if(ptr2 == NULL){
      ptr2 = head1;
    }
  }

  return ptr2;

    
}
