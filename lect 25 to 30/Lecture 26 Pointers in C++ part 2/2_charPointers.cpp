#include<iostream>
using namespace std;
int main(){
    char ch = 'z';
    char *p = &ch;
    cout<<"ch : "<<ch<<endl;
    cout<<"void :: p : "<<static_cast<void*>(p)<<endl;
    cout<<"*p : "<<*p<<endl;
    return 0;
}