#include <iostream>
using namespace std;

/*void reachhome(int scr, int dest) {
  cout << scr << " ";
  // base case
  if (scr == dest) {
    cout << "reached home" << endl;
    return;
  }
  // processing
  scr++;
  // recursive relation
  reachhome(scr, dest);
}

int main() {
  int dest = 10;
  int scr = 1;
  reachhome(scr, dest);
}

//FABINOCCI SERIES

int fib(int n){
  //base case
  if(n==0){
    return 0;
  }
  if(n==1){
    return 1;
  }
  int ans = fib(n-1)+fib(n-2);
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout<<fib(n);
  return 0;
}*/

//CLIMB STAIRS

/*int climbstairs(long long n){
  //base case
  if(n<0){
    return 0;
  }
  if(n==0){
    return 1;
  }
  //recursive relation
  int ans = climbstairs(n-1)+climbstairs(n-2);
  return ans;
}
int main(){
  int n;
  cin>>n;
  cout<<climbstairs(n);
}*/

//SAY DIGITS

void saydigits(int n,string arr[]){
  //base case
  if(n==0){
    return;
  }
  //processing
  int digit=n%10;
  n=n/10;

  //recursive call
  saydigits(n,arr);
  cout<<arr[digit]<<" ";
  
}

int main(){
  string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
  int n;
  cout<<"->"<<" ";
  cin>>n;
  saydigits(n,arr);
}