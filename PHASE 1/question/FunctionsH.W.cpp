#include <iostream>
using namespace std;
/*// PRIME NO 

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    cin>>num;
    if(isPrime(num)){
     cout<<"prime number";   
    }
    else{
        cout<<"not prime number";
    }


    return 0;
}*/
 
 //FABINOCI SERIES 
 /*int fab(int n){
     int a=0;
     int b = 1;
     cout<<a<<" "<<b<<" ";
     for(int i =a;i<=n;i++){
         int c = a+b;
         cout<<c<<" ";
         a=b;
         b=c;
     }
     return a;
 }
 int main(){
     int num;
     cin>>num;
     int ans = fab(num);
     cout<<ans;
 }*/
 
 //ARITHMATIC PROGRESSION
 
 /*int ArithP(int n){
     int ans = (3*n+7);
     return ans;
 }
 int main(){
     int num;
     cin>>num;
     int ans = ArithP(num);
     cout<<ans;
 }*/

//SETBITS
int Setbits(int n){
    int count=0;
    while(n){
        count+=n&1;
        n>>=1;
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    int ans = Setbits(n)+Setbits(m);
    cout<<ans;
}

