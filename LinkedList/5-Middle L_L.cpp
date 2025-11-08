#include <iostream>
using namespace std;       

class Node{
  public:
    int data;
    Node* next;
};
//<---------------1st method-------------------------->
int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node* middleNode(Node* head) {
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
//<---------------------------------->




//<---------------2nd optimal method------------------->
Node* middle(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  if(head->next->next == NULL){
    return head->next;
  }
  Node* slow = head;
  Node* fast = head->next;
  while(fast != NULL){
    fast = fast->next;
    if(fast != NULL){
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
}
//<---------------------------------->



int main(){
  
  return 0;
}
