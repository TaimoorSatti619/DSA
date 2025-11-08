#include <iostream>
using namespace std;

class Parent{
public:

//constructor overloading
// Parent(){
//   cout<<"non-parametrized"<<endl;        
// }
// Parent(int a){
//   cout<<"int : "<<a<<endl;
//   cout<<"parametrized"<<endl;
// }
// <------------------------->
// // function overloading
// void display(int a){
//   cout<<"int : "<<a<<endl;
// }
// void display(char ch){
//   cout<<"char : "<<ch<<endl;
// }
// <------------------------->




//function wla
// void display(){
//   cout<<"Parent"<<endl;
// }

// <------------------------->





// virtual function
virtual void hello(){
  cout<<"hello from parent"<<endl;
}

};
class Child : public Parent{
public:
//constructor overloading
void display(){
  cout<<"Child"<<endl;
}

void hello(){
  cout<<"hello from child"<<endl;
}
};

int main(){
  // Parent p1;
  // p1.display();
  Child c1;
  c1.display();
  c1.hello();





  
  // p1.display(10);
  // p1.display('S');

  return 0;
}
