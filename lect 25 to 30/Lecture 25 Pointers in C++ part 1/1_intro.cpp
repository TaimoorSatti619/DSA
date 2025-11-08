#include<iostream>
using namespace std;
int main(){
    int num = 5;
    // address of 5
    cout<<"Address :"<<&num<<endl;

    // Pointer 
    int *ptr = &num;

    cout<<"Ptr : "<<ptr<<endl;
    cout<<"*Ptr : "<<*ptr<<endl;

    // *ptr = num = value
    // ptr = &n = address
    
    cout<<"num before *ptr++ :"<<num<<endl;
    *ptr=*ptr+1;
    cout<<"num after *ptr++ :"<<num<<endl;
    return 0;
}