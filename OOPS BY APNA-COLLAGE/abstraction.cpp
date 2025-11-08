#include <iostream>
using namespace std;

class Shape{          // abstract class
virtual void draw() = 0;  //  pure virtual function
};
class Circle : public Shape{
public:
void draw(){
cout << "Drawing a circle" << endl;
}
};

class func{
public:
  int x;
  void inc(){
    x=x+1;
  }
};




void fun(){
  static int x = 0;    // static keyword
  cout<<"x is "<<x<<endl;
  x++;
}

int main(){
  // Circle c;
  // c.draw();
  // fun();
  // fun();
  // fun();

  func f;
  func f2;
  f.x=10;
  f2.x=20;
  cout<<f.x;
  

  return 0;
}
