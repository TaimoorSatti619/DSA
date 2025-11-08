#include<iostream>
using namespace std;

// function to print pointer value * is must
void print(int *ptr){
    cout<<*ptr<<endl;
}

int main(){
    int value = 5;
    int *ptr = &value;
    print(ptr);
    return 0;
}