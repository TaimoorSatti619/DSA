#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *bottom;   // for flattening a linklist

  Node(int data) {
    this->data = data;
    this->next = NULL; 
    this->bottom = NULL;  // for flattning linklist
  }
};

//////////////////////////////////////// MERGE SORT /////////////////////////
Node *getMid(Node *head) {
  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *merge(Node *left, Node *right) {
  if (left == NULL) {
    return right;
  }

  if (right == NULL) {
    return left;
  }

  Node *ans = new Node(-1);
  Node *temp = ans;

  while (left != NULL && right != NULL) {
    if (left->data < right->data) {
      temp->next = left;
      temp = left;
      left = left->next;
    } else {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }

  while (left != NULL) {
    temp->next = left;
    temp = left;
    left = left->next;
  }

  while (right != NULL) {
    temp->next = right;
    temp = right;
    right = right->next;
  }

  ans = ans->next;
  return ans;
}

Node *mergeSort(Node *head) {
  // base case
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // find mid
  Node *mid = getMid(head);

  // break into two halves
  Node *left = head;
  Node *right = mid->next;
  mid->next = NULL;

  // recursive calls to sort both halves
  left = mergeSort(left);
  right = mergeSort(right);

  // merge both sorted halves
  Node *result = merge(left, right);

  return result;
}


//*****************************************************************************************************
//////// FLATTEN A LINKLIST /////////////////////

Node* merge2(Node* a, Node* b){
  if(a == NULL){
    return b;
  }
  if(b == NULL){
    return a;
  }

  Node* ans = new Node(-1);
  Node* temp = ans;
  while(a != NULL && b != NULL){
    if(a->data < b->data){
      temp->bottom = a;
      temp = a;
      a = a->bottom;
    }
    else{
      temp->bottom = b;
      temp = b;
      b = b->bottom;
    }
  }

  if(a != NULL){
    temp->bottom = a;
  }
  else{
    temp->bottom = b;
  }

  ans = ans->bottom;
  return ans;
}


Node *flatten(Node *head){
  // base case
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* left = head;
  Node* right = flatten(head->next);
  left->next = NULL;

  Node* result = merge2(left, right);
  return result;
}

int main() { return 0; }