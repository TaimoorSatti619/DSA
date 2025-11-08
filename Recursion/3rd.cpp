#include<iostream>
using namespace std;

//IS SORTED ARRAY

/*bool issorted(int *arr,int n){
  //base case 
  if(n==0 || n==1){
    return true;
  }
  if(arr[0]>arr[1]){
    return false;
  }
  else{
    bool remainingpart=issorted(arr+1,n-1);
    return remainingpart;
  }
}

int main(){
  int arr[5]={1,2,8,4,5};
  bool ans = issorted(arr,5);
  if(ans){
    cout<<"array is sorted";
  }
  else{
    cout<<"array is not sorted";
  }
  return 0;
}*/

// <- SUM OF ARRAY ->

/*int getsum(int *arr,int n){
  //base case
  if(n==0){
    return 0;
  }
  if(n==1){
    return arr[0];
  }
  int remainingpart = getsum(arr+1,n-1);
  int sum = arr[0]+remainingpart;
  return sum;
}
int main(){
  int arr[5]={1,2,3,4,5};
  int ans = getsum(arr,5);
  cout<<"sum is :"<<ans;
}*/

// <- LINEAR SEARCH ->

/*bool linearsearch(int *arr,int n,int k){
  //base case
  if(n==0){
    return false;
  }
  if(arr[0]==k){
    return true;
  }
  else{
    bool remainingpart = linearsearch(arr+1,n-1,k);
    return remainingpart;
  }
}

int main(){
  int arr[6]={2,4,6,1,3,5};
  int key = 2;
  bool ans=linearsearch(arr,6,key);
  if(ans){
    cout<<"key is present";
  }
  else{
    cout<<"key is not present";
  }
  return 0;
}*/

//BINARY SEARCH

bool binarysearch(int *arr,int s,int e,int k){
  //base case
  if(s>e){
    return false;
  }
  int mid = s+(e-s)/2;
  if(arr[mid]==k){
    return true;
  }
  if(arr[mid]<k){
    return binarysearch(arr,mid+1,e,k);
  }
  else{
    return binarysearch(arr,s,mid-1,k);
  }
}

int main(){
  int arr[6]={2,4,6,10,14,18};
  int key = 15;
  bool ans = binarysearch(arr,0,5,key);
  if(ans){
    cout<<"key is present";
  }
  else{
    cout<<"key is not present";
  }
  return 0; 
}