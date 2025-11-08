#include<iostream>
using namespace std;
inline int getMax(int& a, int& b){
    int ans = (a>b) ? a : b ;
    return ans;
}
int main(){
    int a = 5;
    int b = 2;
    int ans = getMax(a,b);     
    cout<<"Ans : "<<ans<<endl;
    return 0;
}
