#include <iostream>
using namespace std;

int main() {
    int num = 5;
    int *p=&num;
    cout<<num<<endl;
    cout<<p<<endl;
    cout<<&num<<endl;
    
    cout<<"sixe of integer is :"<<sizeof(num)<<endl;
    cout<<"sixe of pointer is :"<<sizeof(p)<<endl;
     // pointer size is always 8

    return 0;
} 