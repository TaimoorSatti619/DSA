#include <iostream>
using namespace std;

int Binarysearch(int arr[],int size,int key){
    int start =0;
    int end = size-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start =mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
    
}
int main() {
    int even[6]={2,4,6,8,10,12};
    int odd[5]={2,4,6,8,10};
    
    int Evenans = Binarysearch(even,6,20);
    cout<<"the key is :"<<Evenans<<endl;
    
    int Oddans = Binarysearch(odd,5,15);
    cout<<"the key is :"<<Oddans<<endl;


    return 0;
}