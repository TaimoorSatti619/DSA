#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node* random;

    //constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
    this->random = NULL;
  }
};

class List{
  Node* head;
  Node* tail;

public:
  List(){
    head = tail = NULL;
  }


  // Copy random list
  Node* copyRandomList(Node* head){
    if(head == NULL){
      return NULL;
    }

    unordered_map<Node*,Node*> m;
    Node* newHead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    m[head] = newHead;
    while(oldTemp != NULL){
      Node* copyNode = new Node(oldTemp->data);
      m[oldTemp] = copyNode;
      newTemp->next = copyNode;

      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;
    while(oldTemp != NULL){
      newTemp->random = m[oldTemp->random];
      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    return newHead;
  }
  

};

int main(){
  
  return 0;
}