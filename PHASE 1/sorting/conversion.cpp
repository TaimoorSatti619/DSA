#include <iostream>
using namespace std;

// BINARY TO DECIMAL

int main() {
  /*  int n;
    cin>>n;
    
    int ans = 0;
    int power = 1;
    while(n>0){
       int lastdigit = n%10;
       ans += lastdigit*power;
       power*=2;
       n/=10;
    }
    cout<<ans<<endl;
*/


// DECIMAL TO BINARY
       int n;
       cin>>n;
       
       int ans = 0;
       int power = 1;
       while(n>0){
           int digit = n%2;
           ans += digit*power;
           power *= 10;
           n/=2;
       }
       cout<<ans<<endl;
       

    return 0;
}