// & operator is optional in char during intialization 
// and convert to void is must to print address 
#include<iostream>
using namespace std;
int main(){
    char ch[] = "Shuban";
    cout<<"ch : "<<ch<<endl; // print all array
    char *ptr = ch;  // pointer created
    cout<<"ptr : "<<ptr<<endl;    // print all array
    cout<<"*ptr : "<<*ptr<<endl;  // print first element
    char *ptr1 = &ch[0];         // pointer created
    cout<<"ptr1 : "<<ptr1<<endl;    // print all array element
    cout<<"ptr(address) : "<<static_cast<void*>(ptr)<<endl; // print address
    cout<<"ptr1(address) : "<<static_cast<void*>(ptr1)<<endl; // print address
    return 0;
}