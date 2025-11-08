#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;

Node(int data){
  this->data = data;
  this->next = NULL;
}
};

class List{
  Node* head;
  Node* tail;
public:



Node* mergeSortedLists(Node* head1, Node* head2){    // merge two sorted linked lists
  if(head1 == NULL || head2 == NULL){
    return head1 == NULL ? head2 : head1;
  }

  if(head1->data <= head2->data){
    head1->next = mergeSortedLists(head1->next,head2);
    return head1;
  }
  else{
    head2->next = mergeSortedLists(head1,head2->next);
    return head2;
  }
}

/*
  Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
      forward = curr->next;
      curr->next = prev;

      prev = curr;
      curr = forward;
    }
    return prev;
  }

  Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  } */
};

int main(){

  return 0;
}