#include<iostream>
using namespace std;

int dectobinary(int n){
  int ans =0,pow=1;
  while(n>0){
    int rem=n%2;
    n/=2;
    ans+=rem*pow;
    pow*=10;   
  }
  return ans;
}

int main(){
 //  int n=5;
   for(int i=1;i<=10;i++){
   cout<<"binary of "<< i <<": is :"<<dectobinary(i)<<endl;
 }
 // cout<<dectobinary(n);
  return 0;
}