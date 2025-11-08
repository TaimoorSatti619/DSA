#include<iostream>
using namespace std;
void update(int **p){
    **p = **p+1;
}
int main(){
    int i = 5;
    int *p = &i;
    int **p1 = &p;
    cout<<"before i = "<<i<<endl;
    cout<<"before p = "<<p<<endl;
    cout<<"before p1 = "<<p1<<endl;
    update(p1);
    cout<<"after i = "<<i<<endl;
    cout<<"after p = "<<p<<endl;
    cout<<"after p1 = "<<p1<<endl;
    return 0;
}