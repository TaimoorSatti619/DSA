#include <iostream>
using namespace std;
/*
// SINGLE INHERITANCE✔✔✔✔✔✔✔✔�

class person{      // base class
public:
  string name;
  int age;
  // parametrized constructor
  person(string name,int age){
    this->name=name;
    this->age=age;
    cout<<"base constructor called"<<endl;
  }


  //constructor              pehley base class ka constructor call hoga
  person(){
    cout<<"Base class constructor "<<endl;
  }

  //destructor
  ~person(){
    cout<<"Base class destructor "<<endl;
  }

};


class student:public person{    // derived class
public:
  int rollno;


  // parametrized constructor
  student(string name,int age,int rollno):person(name,age){
    this->rollno = rollno;
    
    cout<<"derived constructor called"<<endl;
  }

  //constructor                                  
  student(){
    cout<<"Derived class constructor "<<endl;
  }

  //destructor                            pehley derive class ka deststructor call hoga
  ~student(){
    cout<<"Derived class destructor "<<endl;
  }

  void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Roll no: "<<rollno<<endl;
  }
};

int main(){
 
  student s( "Alien",19,852);
  // s.name = "Alien";
  // s.age = 19;
  // s.rollno = 58;
  s.display();
  return 0;
}
*/

/*
// MULTI LEVEL INHERITANCE✔✔✔✔✔✔✔✔�

class Parent{
public:
  string name;
};
class Child:public Parent{
public:
  int age;
};
class GrandChild:public Child{
public:
  int rollno;
};
int main(){
  GrandChild gc;
  gc.name = "Parent";
  gc.age = 19;
  gc.rollno = 58;
  cout<<gc.name<<endl;
  cout<<gc.age<<endl;
  cout<<gc.rollno<<endl;
}
*/

/*
// MULTIPLE INHERITANCE✔✔✔✔✔✔✔✔�

class Parent1{
public:
  string name;
};
class Parent2{
public:
  int age;
};
class Child:public Parent1,public Parent2{
public:
  int rollno;
};
int main(){
  Child c;
  c.name = "Parent";
  c.age = 19;
  c.rollno = 58;
  cout<<c.name<<endl;
  cout<<c.age<<endl;
  cout<<c.rollno<<endl;
}
*/

/*
// HIERARCHICAL INHERITANCE✔✔✔✔✔✔✔�

class Parent{
 public: 
  string name;
};
class Child1:public Parent{
public:
  int age;
};
class Child2:public Parent{
public:
  int rollno;
};
int main(){
  
  c.name = "Parent";
  c.age = 19;
  c.rollno = 58;
  cout<<c.name<<endl;
  cout<<c.age<<endl;
  cout<<c.rollno<<endl;
}
*/

/*
// HYBRID INHERITANCE✔✔✔✔✔✔✔�

MIXTURE OF ALL ABOVE INHERITANCES
*/
