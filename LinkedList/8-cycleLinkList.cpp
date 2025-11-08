#include <iostream>
#include <map>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

// approch 1 Detect cycle
bool detectLoop(Node* head){
  if(head == NULL){
    return false;
  }

  map<Node*,bool>visited;
  Node* temp = head;
  while(temp != NULL){
    // mil gya
    if(visited[temp] == true){
      cout<<"CYCLE IS PRESENT AT "<<temp->data<<endl;
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }
  
  return false;
}


// Approch 2 Floyd's cycle detection algorithm

Node* floydDetectLoop(Node* head){
  if(head == NULL){
    return NULL;
  }
  Node* slow = head;
  Node* fast = head;
  while(slow != NULL && fast != NULL){
    fast = fast->next;
    if(fast != NULL){
      fast = fast->next;
    }
    slow = slow->next;

    if(slow == fast){
      cout<<"Cycle is present"<<endl;
      return slow;
    }
  }
  return NULL;
}

//  => get starting node of loop

Node* getStartingNode(Node* head){
  if(head == NULL){
    return NULL;
  }

  // intersection point
  Node* intersection = floydDetectLoop(head);
  if(intersection == NULL){
    return NULL;
  }
  Node* slow = head;
  while(slow != intersection){
    slow = slow->next;
    intersection = intersection->next;
  }
  return slow;  
}


// => remove loop

void removeLoop(Node* head){
  if(head == NULL){
    return;
  }

  Node* startOfLoop = getStartingNode(head);
  if(startOfLoop == NULL){
    return;
  }
  Node* temp = startOfLoop;

  while(temp->next != startOfLoop){
    temp = temp->next;
  }
  temp->next = NULL;
}