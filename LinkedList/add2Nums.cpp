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

// add 2 Numbers represnted by linked list
class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void insertAtTail(Node* &head, Node* &tail, int dig){
        Node* newNode = new Node(dig);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* add(Node* num1, Node* num2){
        int carry = 0;
        Node* head = NULL;
        Node* tail = NULL;
        while(num1 != NULL || num2 != NULL || carry != 0){
            int val1 = 0;
            if(num1 != NULL){
                val1 = num1->data;
            }

            int val2 = 0;
            if(num2 != NULL){
                val2 = num2->data;
            }

            int sum = carry + val1 + val2;
            int dig = sum % 10;

            // insert it in ans
            insertAtTail(head,tail,dig);
            carry = sum/10;
            if(num1 != NULL){
                num1 = num1->next;
            }
            if(num2 != NULL){
                num2 = num2->next;
            }
        }
        return head;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        // step 1 => reverse
        num1 = reverse(num1);
        num2 = reverse(num2);

        // step 2 => add
        Node* ans = add(num1,num2);

        // step 3 => reverse ans
        ans = reverse(ans);

        // for removing 0 at the beginning 
        if(ans != NULL && ans->data == 0 && ans->next != NULL){
            ans = ans->next;
        } 

        return ans;
    }



    //******************************************************************************************************
    // ADD 1 TO A NUMBER REPRESENTED AS A LINK LIST
    
    Node* add1(Node* list){
        int carry = 1;
        Node* head = NULL;
        Node* tail = NULL;

        while(list != NULL || carry != 0){
            int val = 0;
            if(list != NULL){
                val = list->data;
            }

            int sum = carry + val;
            int dig = sum % 10;
            insertAtTail(head,tail,dig);
            carry = sum / 10;

            if(list != NULL){
                list = list->next;
            }
        }

        return head;
    }

    Node* addOne(Node* head){
        // step 1 -> revere
        head = reverse(head);

        // step 2 -> add
        Node* ans = add1(head);

        // step 3-> reverse ans
        ans = reverse(ans);

        return ans;
    }
};




int main() {
    
    return 0;
}

