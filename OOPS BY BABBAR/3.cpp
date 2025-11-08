#include <iostream>
#include <string.h>
using namespace std;

class Hero{
  private:
  int health;
  public:
  char level;
  char *name;

  //constructer 
  Hero(){
    cout<<"constructer bnaya ha"<<endl;
    //shallow copy
    name = new char[100];
  }


  //parameterized constructor
  Hero(int health){
    this->health = health;
  }


  Hero(int health,char level){
    this->health = health;
    this->level = level;
  }



  //copy constructor
  Hero(Hero &temp){
  //deep copy
    char *ch = new char[strlen(temp.name)+1];
    strcpy(ch,temp.name);
    this->name = ch;
    cout<<"copy wala called hua ha"<<endl;
    this->health = temp.health;
    this->level = temp.level;
  }

  void setname(char name[]){
    strcpy(this->name,name);
  }


  int gethealth(){
    return health;
  }
  void sethealth(int h){
    health = h;
  }

  void print(){
    cout<<"NAME :"<<this->name<<endl;
    cout<<"HEALTH :"<<this->health<<endl;
    cout<<"LEVEL :"<<this->level<<endl;  
  }

  //destructor
  ~Hero(){
    cout<<"destructor called"<<endl;
  }
};

int main(){
  
  Hero h1;
  // h1.sethealth(100);
  // h1.level = 'A';
  // char name[10]="taimoor";
  // h1.setname(name);
  
  // // h1.print();

  // Hero h2(h1);
  // // h2.print();

  // h1.name[0] = 's';
  // h1.print();

  // h2.print();
  // //copy assignment operator
  // h1=h2;
  // h1.print();
  // h2.print();
  return 0;
}








  
  // Hero b(100,'A');
  // cout<<"health : "<<b.gethealth()<<endl;
  // cout<<"level : "<<b.level<<endl;
  // //copy constructor
  // Hero c(b);
  // cout<<"health : "<<c.gethealth()<<endl;
  // cout<<"level : "<<c.level<<endl;

