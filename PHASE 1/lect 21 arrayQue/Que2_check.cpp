#include <iostream>
using namespace std;

bool check(int arr[],int n){
    int count=0;
    int m=n;
    for(int i=0;i<n;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[m-1]>arr[0]){
        count++;
    }
    return count<=1;
}
int main(){
    int arr[5]={3,4,5,1,2};
    if(check(arr,5)){
        cout<<"the arrays are rotated to be sorted"<<endl;
    }
    else{
        cout<<"the arrays are not rotated to be sorted"<<endl;
    }
    return 0;
}