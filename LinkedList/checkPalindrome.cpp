#include <iostream>
#include<vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  // constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

//********************************* Check PALINDROME ******************************************************************
//////////////////////////////// APPROCH 1////

bool checkPalindrome(vector<int>arr){
  int s = 0;
  int e = arr.size()-1;
  while(s <= e){
    if(arr[s] != arr[e]){
      return false;
    }
    s++;
    e--;
  }
  return true;
}

bool isPalindrome(Node* &head){   // space complexity 0(n)
  vector<int>arr;                 // time complexity 0(n)
  Node* temp = head;
  while(temp != NULL){
    arr.push_back(temp->data);
    temp = temp->next;
  }
  return checkPalindrome(arr);
}

//********************************************************************************************************
//////////////////////////////////////// APPROCH 2 ////

Node* getMid(Node* head){
  Node* slow = head;
  Node* fast = head->next;
  while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

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

bool is_palindrome(Node* &head){
  if(head == NULL || head->next == NULL){
    return true;
  }
  
  // step 1 => find middle node
  Node* mid = getMid(head);

  // step 2 => reverse list after middle node
  Node* temp = mid->next;
  mid->next = reverse(temp);

  // step 3 => compare both halves
  Node* head1 = head;
  Node* head2 = mid->next;
  while(head2 != NULL){
    if(head1->data != head2->data){
      return false;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  // step 4 =>  repeat step 2 (optional)
  temp = mid->next;
  mid->next = reverse(temp);
  
  return true;
}

//********************************************************************************************************

int main(){

  return 0;
}