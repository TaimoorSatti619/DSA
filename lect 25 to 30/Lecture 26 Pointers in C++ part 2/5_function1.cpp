#include<iostream>
using namespace std;
// update function directly access the value in main and update it
// address cant be updated in this way
void update(int *p){
    *p = *p+1;
}
void print(int *p){
    cout<<*p<<endl;
}
int main(){
    int value = 5;
    int *p = &value;
    update(p);
    print(p);
    return 0;
}