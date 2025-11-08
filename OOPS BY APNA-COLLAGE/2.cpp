#include <iostream>
using namespace std;

class Teacher{
private:

public:
  //attributes  or properties
  string name;
  string dept;
  string subject;
  double salary;

  // non-parameterized constructor
  Teacher(){
    cout<<"I am Constructor "<<endl;
    dept = "computer science";
  }


  //parameterized constructor
  // Teacher(string n, string d, string s, double sal){
  //   name = n;
  //   dept = d;
  //   subject = s;
  //   salary = sal;
  // }

  Teacher(string name, string dept, string subject, double salary){
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
  }

// copy constructor    custom
  Teacher(Teacher &t){      
    this->name = t.name;
    this->dept = t.dept;
    this->subject = t.subject;
    this->salary = t.salary;
  }
  






  void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Dept: "<<dept<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Salary: "<<salary<<endl;
  }
};


int main(){
  
  Teacher t1;    // constructor autmaticaly called when object is created
  cout<<t1.dept<<endl<<endl;

  Teacher t2("Babbar", "Computer Science", "C++", 50000);
  // t2.display();


//copy constructor
  Teacher t3(t2);
  t3.display();

  return 0;
}