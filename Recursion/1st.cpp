#include <iostream>
using namespace std;

/*int factorial(int n){
  //base case
  if(n==0){
    return 1;
  }
  int chotti = factorial(n-1);
  int badi = n*chotti;
  return badi;
}

int main(){
  cout<<"enter number "<<endl;
  int n;
  cin>>n;
  int ans = factorial(n);
  cout<<ans;
}*/

// POWER OF 2

/*int power(int n){
  //base case
  if(n==0){
    return 1;
  }
  //recursive case
  int smaller = power(n-1);
  int bigger = 2*smaller;
  return bigger;
}

int main(){
  int n;
  cout<<"enter number "<<endl;
  cin>>n;
  int ans = power(n);
  cout<<ans;

}*/

// PRINT COUNTING

void print(int n) {
  // base case
  if (n == 0) {
    return;
  }
  // recursive case
  print(n - 1);
  cout << n << endl;
}

int main() {
  int n;
  cout << "enter number " << endl;
  cin >> n;
  print(n);
}