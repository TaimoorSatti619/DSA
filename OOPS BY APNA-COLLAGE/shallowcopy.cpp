#include <iostream>
using namespace std;

class Student{
public:
  string name;
  double *cgpaptr;

  Student(string name, double cgpa){
    this->name = name;
    cgpaptr = new double;
    *cgpaptr = cgpa;
  }

  //shallow copy
  Student(Student &s){
    this->name = s.name;
    cgpaptr = new double;      // just change it
    *cgpaptr = *s.cgpaptr;
    // this->cgpaptr = s.cgpaptr;
    
  }
  
  // destructor                        // dealocating memory
  ~Student(){
    cout<<"HELLO I AM DISTRUCTOR "<<endl;
    delete cgpaptr;        // for deleting heap 
  }


  void display(){
    cout<<"NAME : "<<name<<endl;
    cout<<"CGPA : "<<*cgpaptr<<endl;
  }
};


int main(){
  Student s1("BABBAR",9.2);
  s1.display();

  cout<<endl;
  
  Student s2(s1);
  s2.name = "SHRADDA";
  *(s2.cgpaptr) = 10.2;
  s2.display();
  s1.display();

  

  return 0;
}