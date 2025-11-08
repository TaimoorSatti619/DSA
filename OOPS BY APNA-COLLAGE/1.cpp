#include <iostream>
using namespace std;

class Teacher{
private:
  double salary;
public:
  //attributes  or properties
  string name;
  string dept;
  string subject;

  //metods  or member functions
  void changedept(string newdept){
    dept = newdept;
  }
  //setter
  void setsalary(double s){  // for private member
    salary = s;
  }
  //getter
  double getsalary(){
    return salary;
  }  
};

class student{
public:
  string name;
  int age;
  int rollno;
  string dept;
  string teacher;

};

void line(){
  for(int i =0;i<40;i++){
    cout<<"-";
  }cout<<endl;
}

int main(){
  
  Teacher t1;

  line();
  t1.name = "Babbar";
  t1.dept = "Science";
  t1.subject = "DSA";  
  cout<<"Teacher name is "<<t1.name<<endl;
  cout<<"Teacher Dept is "<<t1.dept<<endl;
  cout<<"Teacher subject is "<<t1.subject<<endl;
  t1.setsalary(25000);
  cout<<"Teacher salary is "<<t1.getsalary()<<endl;
  t1.changedept("Maths");
  cout<<"Teacher New Dept is "<<t1.dept<<endl;
  line();
  
  line();
  student s1;
  s1.name = "Alien";
  s1.rollno = 58;
  s1.age = 19;
  s1.dept = "Computer Science";
  s1.teacher = t1.name;
  cout<<"Student name is "<<s1.name<<endl;
  cout<<"Student rollno is "<<s1.rollno<<endl;
  cout<<"Student age is "<<s1.age<<endl;
  cout<<"Student dept is "<<s1.dept<<endl;
  cout<<"Student teacher is "<<s1.teacher<<endl;
  line();

  student s2;
  cout<<"Enter student name: ";
  cin>>s2.name;
  cout<<"Student name is "<<s2.name<<endl;
  line();

  return 0;
}