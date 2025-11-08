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

/// DETECT LOOP IN LINKED LIST

bool hasCycle(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

/// REMOVE LOOP IN LINKED LIST
Node *detectCycle(Node *head) {
  Node *slow = head;
  Node *fast = head;
  bool cycle = false;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      cycle = true;
      break;
    }
  }
  if (!cycle) {
    return NULL;
  }
  slow = head;
  Node *prev = NULL; /// for removing loop
  while (slow != fast) {
    slow = slow->next;
    prev = fast; // <- for removing loop
    fast = fast->next;
  }

  prev->next = NULL; // <- for removing loop
  return slow;
}