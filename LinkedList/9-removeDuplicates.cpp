#include<iostream>
#include<map>
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

Node* removeDuplicates(Node* head){  // sorted linklist case      // O(n)
  if(head == NULL){
    return NULL;
  }

  Node* curr = head;
  while(curr != NULL){
    
    if((curr->next != NULL) && curr->data == curr->next->data){
      Node* next_next = curr->next->next;
      Node* deleteNode = curr->next;
      delete(deleteNode);
      curr->next = next_next;
    }
    else{
      curr = curr->next;
    }
  }
  return head;
}


 // unsorted linklist case
Node* remove_Duplicates(Node* head){   // O(n^2)   Brute force
  if(head == NULL){
    return NULL;
  }
  
  Node* curr = head;
  while(curr != NULL){
    Node* curr2 = curr;
    
    while(curr2->next != NULL){
      if(curr->data == curr2->next->data){
        Node* next_next = curr2->next->next;
        delete(curr2->next);
        curr2->next = next_next;
      }
      else{
        curr2 = curr2->next;
      }
    }
    curr = curr->next;
  }
  return head;
}

// APPROCH 2  MAP METHOD
Node* removeDuplicates2(Node* head){
  if(head == NULL){
    return NULL;
  }

  map<int,bool>visited;
  Node* curr = head;
  Node* prev = NULL;
  
  while(curr != NULL){
    if(visited[curr->data] == true){
      prev->next = curr->next;
      delete(curr);
    }
    else{
      visited[curr->data] = true;
      prev = curr;
    }
    curr = prev->next;
  }
  return head;
}



// APPROCH 3  sort method

// split 
void split(Node* head, Node* &a, Node* &b){
  Node* slow = head;
  Node* fast = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  a = head;
  b = slow->next;
  slow->next = NULL;
}

Node* merge(Node* a, Node* b){
  if(a == NULL || b == NULL){
    return a == NULL ? b : a;
  }
  if(a->data <= b->data){
    a->next = merge(a->next,b);
    return a;
  }
  else{
    b->next = merge(a,b->next);
    return b;
  }
}

Node* mergeSort(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  Node* front;
  Node* back;
  // split list
  split(head,&front,&back);
  front = mergeSort(front);
  back = mergeSort(back);
  // merge
  return merge(front,back);
}




int main(){

  return 0;
}

