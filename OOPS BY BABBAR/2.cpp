// #include <iostream>
// using namespace std;

// class Hero{
//   private:
//   int health;
//   public:
//   char level;

//   //constructer 
//   Hero(){
//     cout<<"constructer bnaya ha"<<endl;
//   }
//   //parameterized constructor
//   Hero(int health){
//     this->health = health;
//   }
//   Hero(int health,char level){
//     this->health = health;
//     this->level = level;
//   }
//   //copy constructor
//   Hero(Hero &temp){
//     cout<<"copy wala called hua ha"<<endl;
//     this->health = temp.health;
//     this->level = temp.level;
//   }


  
//   // private:
//   int gethealth(){
//     return health;
//   }
//   void sethealth(int h){
//     health = h;
//   }
// };

// int main(){

//   Hero b(100,'A');
//   cout<<"health : "<<b.gethealth()<<endl;
//   cout<<"level : "<<b.level<<endl;
//   //copy constructor
//   Hero c(b);
//   cout<<"health : "<<c.gethealth()<<endl;
//   cout<<"level : "<<c.level<<endl;














  //static 
  // Hero a(10);
  // cout<<"health : "<<a.gethealth()<<endl;
  // Hero b(100,'A');
  // cout<<"health : "<<b.gethealth()<<endl;
  // cout<<"level : "<<b.level<<endl;
  
  //dynamic
  // Hero* b = new Hero;

//   return 0;
// }