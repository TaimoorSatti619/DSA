#include<iostream>
using namespace std;

void input(int *arr, int& n){
    cout<<"Enter Array Elements : ";
    for(int i=0; i<n; i++){
        cin>>i[arr];
    }
    cout<<endl;
}

void print(int *arr, int& n){
    for(int i=0; i<n;i++){
        cout<<i[arr]<<" ";
    }
    cout<<endl;
}
int getSum(int *arr, int& n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=i[arr];
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter value for n : ";
    cin>>n;
    int *arr = new int[n]; // array created in heap
    input(arr,n);
    cout<<"Original array is : "<<endl;
    print(arr,n);
    int sum = getSum(arr,n);
    cout<<"Sum : "<<sum<<endl;
    delete[] arr;
    return 0;
}