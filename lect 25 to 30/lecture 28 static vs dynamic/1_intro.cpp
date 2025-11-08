#include<iostream>
using namespace std;
int main(){
    int i=5;
    int& j = i; // refrence var created
    cout<<"i : "<<i<<endl;
    cout<<"j : "<<j<<endl;
    i++;
    cout<<"j after i++ : "<<j<<endl;
    j++;
    cout<<"i after j++ : "<<i<<endl;
     cout<<"i : "<<i<<endl;
    cout<<"j : "<<j<<endl;
    
    return 0;
}