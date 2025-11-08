#include<iostream>
using namespace std;
int main(){
    // *ptr = i = value || ptr = &i = address
    // var and its pointer data type should be same 
    int i=5;
    // pointer
    int *ptr = &i;

    cout<<"Value of i : "<<i<<endl;
    cout<<"Value of *ptr : "<<*ptr<<endl;
    cout<<"Value of ptr : "<<ptr<<endl;

    // size of pointer (mostly 8)
    cout<<"Size of Pointer : "<<sizeof(ptr)<<endl;

    (*ptr)++;
    cout<<"After (*ptr)++ : "<<*ptr<<endl;
    i--;
    cout<<"After i-- : "<<i<<endl;

    // Copy one pointer to another
    int *q = ptr;
    cout<<"Pointer ptr copied to *q "<<endl;
    (*q)++;
    cout<<"value of *q after (*q)++ : "<<(*q)<<endl;
    cout<<"Value of *ptr after *q++ : "<<*ptr<<endl;
    cout<<"value of i : "<<i<<endl;
    cout<<"Address of ptr : "<<ptr<<endl;
    cout<<"Address of q : "<<q<<endl;

    cout<<"Value of ptr : "<<ptr<<endl;
    cout<<"Value of ptr+1 : "<<ptr+1<<endl; // ptr+1 will go to the next location 
    
    return 0;
}