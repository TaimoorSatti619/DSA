#include<iostream>
using namespace std;
void printArray(int *arr, int n = 5){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    cout<<"No size given "<<endl;
    printArray(arr);
    cout<<endl<<"size given 3 "<<endl;
    printArray(arr,3);
    cout<<endl;
    return 0;
}
