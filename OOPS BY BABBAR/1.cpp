#include <iostream>
using namespace std;

// class Hero{
//   private:
//   int health;
//   public:
//   char level;
//   // private:
//   int gethealth(){
//     return health;
//   }
//   void sethealth(int h){
//     health = h;
//   }
// };

// int main(){

//   Hero alien;
//   // cout<<"size of alien is "<<sizeof(alien)<<endl;             // empty
//   class ka size 1 huta ha alien.sethealth(400); cout<<"health :"
//   <<alien.gethealth()<<endl; return 0;
// }

// class Alien {
// private:
//   string cnic = "3xxxx-xxxxxxx-7";
//   int networth = 10;

// public:
//   string name = "Taimoor Tahir";
//   int age = 19;
//   double height = 5.5;

//   // getter
//   string getcnic() { return cnic; }
//   int getnetworth() { return networth; }
//   // setter

//   void setnetworth(int n) { networth = n; }
// };

// int main() {

//   // static allocation
//   Alien Taimoor;
//   cout << "size of alien is : " << sizeof(Taimoor) << endl;
//   cout << endl;
//   cout << "Name : " << Taimoor.name << endl;
//   cout << endl;
//   cout << "Age : " << Taimoor.age << endl;
//   cout << endl;
//   cout << "Height : " << Taimoor.height << endl;
//   cout << endl;
//   // acces using getter
//   cout << "CNIC : " << Taimoor.getcnic() << endl;
//   cout << endl;
//   cout << "NetWorth : " << Taimoor.getnetworth() << "Rs" << endl;
//   // acces using setter
//   Taimoor.setnetworth(5);
//   cout << "sory ghalat networth hu gahi" << endl;
//   // using getter
//   cout << "NetWorth : " << Taimoor.getnetworth() << "Rs" << endl;

//   cout<<endl;
//   //dynamic allocation
//   Alien *b = new Alien;
//   cout << "Name : " << (*b).name << endl;
//   cout << endl;
//   cout << "Age : " << (*b).age << endl;
//   cout << endl;
//   cout << "Height : " << (*b).height << endl;
//   cout << endl;
//   // acces using getter
//   cout << "CNIC : " << (*b).getcnic() << endl;
//   cout << endl;
//   cout << "NetWorth : " << (*b).getnetworth() << "Rs" << endl;
//   // acces using setter
//     b->setnetworth(5);                                           // ->  can also be used to access
//   cout << "sory ghalat networth hu gahi" << endl;
//   // using getter
//   cout << "NetWorth : " << (*b).getnetworth() << "Rs" << endl;


  
//   return 0;
// }