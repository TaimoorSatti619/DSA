#include<iostream>
using namespace std;
void update(int& n){
    n=n+1;
}
int main(){
    int i = 5;
    cout<<"Before i : "<<i<<endl;
    update(i);
    cout<<"After i : "<<i<<endl;
    return 0;
}