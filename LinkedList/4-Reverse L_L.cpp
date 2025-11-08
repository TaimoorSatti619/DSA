#include <iostream>
using namespace std;       

class Node{
  public:
    int data;
    Node* next;
};


//<--------ITERATIVE METHOD-------->
Node * reverseLinkList(Node * head){
  if(head == NULL || head->next == NULL){
    return head;
  }

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
//<---------------------------------->



//<--------RECURSIVE METHOD 2-------->
void reverse(Node* &head,Node* curr,Node* prev){
    // base case
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;
}

Node* reverseLinkListRecursive(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  reverse(head,curr,prev);
  return head;
}

//<---------------------------------->


//<--------RECURSIVE METHOD 3-------->
Node* reverseLinkListRecursive2(Node* head){
  // base case
  if(head == NULL || head->next == NULL){
    return head;
  }
  Node* chootahead = reverseLinkListRecursive2(head->next);
  head->next->next = head;
  head->next = NULL;
  
  return chootahead;
}
//<---------------------------------->







void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){

  return 0;
}
