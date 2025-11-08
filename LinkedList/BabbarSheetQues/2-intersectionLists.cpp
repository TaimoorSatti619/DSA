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

//// INTERSECTION OF TWO  SORTED LINKED LISTS /////////////

void insertAtTail(Node *&tail, int data) {
  Node *newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;
}

Node *findIntersection(Node *head1, Node *head2) {
  Node *ans = new Node(-1);
  Node *ansHead = ans;
  Node *ansTail = ans;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data == head2->data) {
      insertAtTail(ansTail, head1->data);
      head1 = head1->next;
      head2 = head2->next;
    } 
    else if (head1->data < head2->data) {
      head1 = head1->next;
    }
    else {
      head2 = head2->next;
    }
  }

  return ansHead->next;
}
