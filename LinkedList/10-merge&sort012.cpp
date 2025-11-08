#include<iostream>
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

// APPROCH 1
Node* sort0s1s2s(Node* head){
  int zeroCnt = 0;
  int oneCnt = 0;
  int twoCnt = 0;

  Node* curr = head;
  while(curr != NULL){
    if(curr->data == 0){
      zeroCnt++;
    }
    else if(curr->data == 1){
      oneCnt++;
    }
    else if(curr->data == 2){
      twoCnt++;
    }
    curr = curr->next;
  }
  
  curr = head;
  while(curr != NULL){
    if(zeroCnt != 0){
      curr->data = 0;
      zeroCnt--;
    }
    else if(oneCnt != 0){
      curr->data = 1;
      oneCnt--;
    }
    else if(twoCnt != 0){
      curr->data = 2;
      twoCnt--;
    }
    curr = curr->next;
  }
  return head;
}


// APPROCH 2
void insertAtTail(Node* &tail,Node* temp){
  tail->next = temp;
  tail = temp;
}

Node* sort0_1_2(Node* head){
  Node* zeroHead = new Node(-1);
  Node* zeroTail = zeroHead;
  Node* oneHead = new Node(-1);
  Node* oneTail = oneHead;
  Node* twoHead = new Node(-1);
  Node* twoTail = twoHead;

  Node* curr = head;
  while(curr != NULL){
    if(curr->data == 0){
      insertAtTail(zeroTail,curr);
    }
    else if(curr->data == 1){
      insertAtTail(oneTail,curr);
    }
    else if(curr->data == 2){
      insertAtTail(twoTail,curr);
    }
    curr = curr->next;
  }
  
  if(oneHead->next != NULL){
    zeroTail->next = oneHead->next;
  }
  else{
    zeroTail->next = twoHead->next;
  }
  oneTail->next = twoHead->next;
  twoTail->next = NULL;

  head = zeroHead->next;
  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return head;
}

//****************************************************************************************************



/////////////////////////////////MERGE TWO SORTED LINKLISTS ////////////////////////////////////////

Node* solve(Node* first,Node* second){
  // if only one element in first list
  if(first->next == NULL){
    first->next = second;
    return first;
  }

  Node* curr1 = first;
  Node* next1 = curr1->next;
  Node* curr2 = second;
  Node* next2 = NULL;
  while(next1 != NULL && curr2 != NULL){
    if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
      // add curr2 in between curr1 and next1
      curr1->next = curr2;
      next2 = curr2->next;
      curr2->next = next1;
      // update pointers
      curr1 = curr2;
      curr2 = next2;
    }
    else{
      // curr1 aur next1 ko aage badhao
      curr1 = next1;
      next1 = next1->next;
      if(next1 == NULL){
        curr1->next = curr2;
        return first;
      }
    }
  }
  return first;
}

Node* mergeTwoLists(Node* head1,Node* head2){
  if(head1 == NULL){
    return head2;
  }
  if(head2 == NULL){
    return head1;
  }

  if(head1->data <= head2->data){
    return solve(head1,head2);
  }
  else{
    return solve(head2,head1);
  }
}

//****************************************************************************************************
int main(){

  return 0;
}