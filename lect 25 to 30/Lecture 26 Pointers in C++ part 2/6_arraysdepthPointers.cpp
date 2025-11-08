#include<iostream>
using namespace std;
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getsum(int *arr, int n){    // *arr = arr[] as in any function arr address is taken as perimeter
    int sum =0;       // as in function arr is just address so size will be 8
    for(int i=0; i<n; i++){
        sum = sum + i[arr];
    }
    return sum;
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<"Sum : "<<getsum(arr,5)<<endl;
    cout<<"Sum last three elements : "<<getsum(arr+2,3)<<endl; // as array is takes as pointer so we can pas any part as we want
    return 0;
}