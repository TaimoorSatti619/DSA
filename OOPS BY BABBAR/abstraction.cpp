#include <iostream>
using namespace std;
// operator overloading
class A{
public:
  int a;
  int b;


  void operator()(A &obj){
    int val1 = this->a;
    int val2 = obj.b;
    cout<<"output: "<<val2*val1<<endl;
  }

};

int main(){
  A obj1,obj2;
  obj1.a = 4;
  obj2.b = 2;
  (obj1)(obj2);
  

  return 0;
}
