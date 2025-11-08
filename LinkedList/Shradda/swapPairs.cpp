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

//////////////////////////////////SWAP NODES IN PAIRS ///////////////////////////////////////////
Node* swapPairs(Node* head){   // O(n)
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* fst = head;
    Node* sec = head->next;
    Node* prev = NULL;
    while(fst != NULL && sec != NULL){
        Node* thrd = sec->next;
        
        fst->next = thrd;
        sec->next = fst;

        if(prev != NULL){
            prev->next = sec;
        } else{
            head = sec;
        }

        // update
        prev = fst;
        fst = thrd;
        if(thrd != NULL){
            sec = thrd->next;
        } else{
            sec = NULL;
        }        
    }
    return head;
}

//*********************************************************************************************


};




int main() {
    
    return 0;
}

