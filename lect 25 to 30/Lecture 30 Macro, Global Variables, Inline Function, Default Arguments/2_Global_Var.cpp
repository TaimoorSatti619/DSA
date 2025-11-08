#include<iostream>
using namespace std;
float PI = 3.14;        // Golbal Var as top from every function

void update(int& i){
    i = i+1;
    cout<<"PI in update function : "<<PI<<endl;
    PI++;    // can be changed original in any function ->bad practice
}
int main(){
    int i = 5;
    cout<<"Before : "<<i<<endl;
    update(i);
    cout<<"After : "<<i<<endl;
    cout<<"PI in main function : "<<PI<<endl;
    return 0;
}
