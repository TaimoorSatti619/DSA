#include <iostream>
using namespace std;

/* Linked list Node */
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class list{
    Node* head;
    Node* tail;
  public:
    list(){
      head=NULL;
      tail=NULL;
    }

// ////////////////////////////////reverse Nodes in k group

Node* reverseKGroup(Node* head, int k){
    Node* temp = head;
    int cnt = 0;
    // step 1 => check if nodes exist in K group
    while(cnt < k){
        if(temp == NULL){
            return head;
        }
        temp = temp->next;
        cnt++;
    }

    // step 2 => recusive call for next
    Node* prev = reverseKGroup(temp, k);

    // step 3 => reverse the current group
    temp = head;
    cnt = 0;
    while(cnt < k){
        Node* forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
        cnt++;
    }

    return prev;   
}


};




int main() {
    
    return 0;
}

