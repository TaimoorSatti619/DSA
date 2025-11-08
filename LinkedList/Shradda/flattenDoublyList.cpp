#include <iostream>
#include<vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node* prev;
  Node* child;

  // constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
    this->child = NULL;
  }
};

class DoublyLinkedList{
  Node* head;
  Node* tail;
public:
  DoublyLinkedList(){
    head = NULL;
    tail = NULL;
  }

//**********************************************************************************************
  ///////////////////////////////// FLATTEN A MULTILEVEL DOUBLY LINKED LIST
  Node* flatten(Node* head){
    // base case
    if(head == NULL){
      return head;
    }

    Node* curr = head;
    while(curr != NULL){
      if(curr->child != NULL){
        Node* forward = curr->next;
        // step 1 => flatten child nodes
        curr->next = flatten(curr->child);
        curr->next->prev = curr;
        curr->child = NULL;
        
        // step 2 => find tail node
        while(curr->next != NULL){
          curr = curr->next;
        }

        // step 3 => connect tail node with forward node
        if(forward != NULL){
          curr->next = forward;
          forward->prev = curr;
        }
      }
      curr = curr->next;
    }
    return head;
  }
//**********************************************************************************************
};

int main(){

  return 0;
}