#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    // starting location of array
    cout<<"arr : "<<arr << endl;
    cout<<"&arr : "<<&arr << endl;
    cout<<"&arr[0] : "<<&arr[0] << endl;

    cout<<"*arr : "<<*arr << endl;
    cout<<"*arr+1 : "<<*arr+1 << endl;
    cout<<"*(arr+1) : "<<*(arr+1) << endl;
    cout<<"*(arr)+1 : "<<*(arr)+1 << endl;

    cout<<"arr[2] : "<<arr[2] << endl;
    cout<<"*(arr+2) : "<<*(arr+2) << endl;

    cout<<"3[arr] : "<<3[arr] <<endl;
    cout<<"*(3+arr) : "<<*(3+arr) <<endl;

    // pointer created 
    cout<<"Pointer created  "<<endl;
    int *p = &arr[0];
    cout<<"arr[0] : "<<arr[0] <<endl;
    cout<<"&arr[0] : "<<&arr[0] <<endl;
    
    cout<<"p : "<<p << endl;
    cout<<"&p : "<<&p << endl;
    cout<<"p+1 : "<<p+1 <<endl;
    cout<<"*p : "<<*p+1 << endl;

    cout<<"Size of arr[5] : "<<sizeof(arr) << endl;
    cout<<"Size of &arr : "<<sizeof(&arr) <<endl;

    return 0;
}

/*

array name is maped to the address location of first 
element in the array.

in array case poniter store just location of one element
for other it process considring first location

you can not do arr = arr + 1
because its by default saved 1st location 
and you can not change this 


*/