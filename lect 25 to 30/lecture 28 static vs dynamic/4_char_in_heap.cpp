#include<iostream>
using namespace std;
int main(){
  char *ch = new char;
  *ch = 'z';
  cout<<"*ch : "<<*ch<<endl;
  cout<<"ch : "<<static_cast<void*>(ch)<<endl;
  delete ch;
  return 0;
}