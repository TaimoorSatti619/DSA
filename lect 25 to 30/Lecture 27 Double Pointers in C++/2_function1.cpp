#include<iostream>
using namespace std;
void update(int **p){
    p = p+1;
}
int main(){
    int i = 5;
    int *p = &i;
    int **p1 = &p;
    cout<<"before i = "<<i<<endl;
    update(p1);
    cout<<"after i = "<<i<<endl;
    return 0;
}