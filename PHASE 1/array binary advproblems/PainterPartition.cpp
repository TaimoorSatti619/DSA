#include <iostream>
using namespace std;

bool ispossible(int arr[],int n,int k,int mid){
    int paintercount=1;
    int boardsum=0;
    for(int i=0;i<n;i++){
        if(boardsum+arr[i] <= mid){
            boardsum+=arr[i];
        }
        else{
            paintercount++;
            if(paintercount > k || arr[i] > mid){
                return false;
            }
            boardsum=arr[i];
        }
    }
    return true;
}

int painterpartition(int arr[],int n,int k){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int s =0;
    int e =sum;
    int mid = s +(e-s)/2;
    int ans =-1;
    while(s <= e){
        if(ispossible(arr,n,k,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}

int main() {
    int arr[4]={10,20,30,40};
    int k = 2;
    int ans = painterpartition(arr,4,2);
    cout<<ans;
    
}