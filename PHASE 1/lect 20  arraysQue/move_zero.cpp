#include <iostream>
using namespace std;

void movezero(int arr[],int n){
    int i = 0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main() {
    int arr[6]={1,0,4,0,0,2};
    movezero(arr,6);
    print(arr,6);
    return 0;
}