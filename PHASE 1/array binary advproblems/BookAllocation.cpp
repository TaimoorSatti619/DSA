#include <iostream>
using namespace std;

bool ispossible(int arr[],int n,int m,int mid){
    int studentcount = 1;
    int pagesum = 0;
    for(int i=0;i<n;i++){
        if(pagesum+arr[i] <=mid){
            pagesum+=arr[i];
        }
        else{
            studentcount++;
            if(studentcount > m || arr[i] > mid){
                return false;
            }
            pagesum=arr[i];
        }
    }
    return true;
}

int Allocatebooks(int arr[], int n, int m){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum =sum+arr[i];
    }
    int s =0;
    int e = sum;
    int mid = s +(e-s)/2;
    int ans = -1;
    
    while(s <= e){
        if(ispossible(arr,n,m,mid)){
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
    int arr[4]={5,17,100,11};
    int m = 4;
    
    int ans = Allocatebooks(arr,4,4);
    cout<<ans;

    return 0;
}