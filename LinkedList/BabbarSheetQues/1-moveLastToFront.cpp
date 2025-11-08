#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

//////////////////////////// MOVE LAST ELEMENT TO FRONT /////////////////////

Node *moveLastToFront(Node *head) {

  // for empty or one Node
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *curr = head;
  Node *prev = NULL;

  while (curr->next != NULL) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = NULL;
  curr->next = head;
  head = curr;
  return head;
}

//*****************************************************************************************