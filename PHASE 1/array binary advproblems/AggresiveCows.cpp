#include <iostream>
#include <algorithm>
using namespace std;

bool ispossible(int arr[],int n,int k,int mid){
    int cowcount  =1;
    int lastpos = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i]-lastpos >= mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos = arr[i];
        }
    }
    return false;
}

int aggresivecows(int arr[],int n, int k){
    sort(arr,arr+n);
    int maxi= arr[n-1];
    int s =0;
    int e = maxi;
    int mid = s +(e-s)/2;
    int ans = -1;
    while(s <= e){
        if(ispossible(arr,n,k,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}
int main() {
    int arr[5]={4,2,1,3,6};
    int k = 2;
    int ans = aggresivecows(arr,5,2);
    cout<<ans;

    return 0;
}