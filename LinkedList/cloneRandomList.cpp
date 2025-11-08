#include <iostream>
#include <unordered_map>
using namespace std;

/* Linked list Node */
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
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

//////////////////////////////////CLONE LINLIST WITH RANDOM POINTERS ///////////////////////////////////////////

//************************************* APPROCH 1 ****************************************************

    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head){  // TC: O(N)
        // step 1 => create clone      // SC: O(N)
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2 => create a  map
        unordered_map<Node*, Node*> map;
        Node* orignal = head;
        Node* clone = cloneHead;
        while(orignal != NULL){
            map[orignal] = clone;
            orignal = orignal->next;
            clone = clone->next;
        }

        // step 3 => copy random pointers
        orignal = head;
        clone = cloneHead;
        while(orignal != NULL){
            clone->random = map[orignal->random];
            orignal = orignal->next;
            clone = clone->next;
        }
        
        return cloneHead;
    }



//*******************************************************************************************************************


//************************************* APPROCH 2 **********************************************************************

    Node* copyRandomList2(Node* head){
        // step 1 => create clone      
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2 => clone Node add in between orignal

        Node* orignal = head;
        Node* clone = cloneHead;
        while(orignal != NULL && clone != NULL){
            Node* forward = orignal->next;
            orignal->next = clone;
            orignal = forward;

            forward = clone->next;
            clone->next = orignal;
            clone = forward;
        }
        
        // step 3 => copy random pointers

        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }

        // step 4 => revert changes done in step 2

        orignal = head;
        clone = cloneHead;
        while(orignal != NULL && clone != NULL){
            orignal->next = clone->next;
            orignal = orignal->next;

            if(orignal != NULL){
                clone->next = orignal->next;
            }
            clone = clone->next;
        }

        // step 5 => return ans
        return cloneHead;    
    }

//*******************************************************************************************************************
};




int main() {
    
    return 0;
}

