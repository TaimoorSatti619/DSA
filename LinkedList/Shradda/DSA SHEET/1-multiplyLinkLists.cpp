#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

////// MULTIPLY TWO LINKED LISTS //////
long long multiplyTwoLists(Node *first, Node *second) {
  long long MOD = 1000000007;
  long long num1 = 0;
  long long num2 = 0;

  while (first != NULL) {
    num1 = (num1 * 10) + first->data;
    first = first->next;
  }

  while (second != NULL) {
    num2 = (num2 * 10) + second->data;
    second = second->next;
  }

  return (num1 * num2) % MOD;
}