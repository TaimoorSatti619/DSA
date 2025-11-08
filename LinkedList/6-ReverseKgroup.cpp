#include <iostream>
using namespace std;       

class Node{
  public:
    int data;
    Node* next;

};

// <-------------------------------------------->

Node* reverseKGroup(Node* head,int k){
  // base case
  if(head == NULL){
    return NULL;
  }
  // reverse first k nodes
  Node* forward = NULL;
  Node* curr = head;
  Node* prev = NULL;
  int cnt = 0;
  while(curr != NULL && cnt < k){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    cnt++;
  }

  // recursion call
  if(forward != NULL){
    head->next = reverseKGroup(forward,k);
  }

  return prev;
}
// <-------------------------------------------->

// ye ju neechey likha ha yeh bhi wohi ha bas aik edge case ha ju handle kiya ha

// <-------------------------------------------->
int getLength(Node* head){
  int cnt = 0;
  while(head != NULL){
    cnt++;
    head = head->next;
  }
  return cnt;
}


Node* reverseKGroup2(Node* head,int k){
  // base case                // agr neechey nhi likhna tu phir yeh base case loo bas
  if(head == NULL ){       //if(head == NULL || getLength(head) < k){
    return NULL;            //  return head;                            
  }                        // }
                    
  // reverse first k nodes
  Node* forward = NULL;
  Node* curr = head;
  Node* prev = NULL;
  int cnt = 0;
  while(curr != NULL && cnt < k){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    cnt++;
  }

  // recursion call
  if(forward != NULL){
    // head->next = reverseKGroup2(forward,k);
    if(getLength(forward) >= k){                    
      head->next = reverseKGroup2(forward,k);
    }
    else{
      head->next = forward;
    }
  }

  return prev;
}

// <-------------------------------------------->
