#include<iostream>
using namespace std;

// <-MERGE SORT ->

void merge(int *arr,int s,int e){
  int mid = s +(e-s)/2;
  int len1 = mid -s +1;
  int len2 = e - mid;

  int *first = new int[len1];
  int *second = new int[len2];
  //copy values
  int mainarrayindex = s;
  for(int i=0;i<len1;i++){
    first[i] = arr[mainarrayindex++];
  }
  mainarrayindex = mid+1;    
  for(int i=0;i<len2;i++){
    second[i] = arr[mainarrayindex++];
  }
  //merge 2 sorted arrays
  int index1= 0;
  int index2= 0;
  mainarrayindex = s;

  while(index1<len1 && index2<len2){
    if(first[index1]<second[index2]){
      arr[mainarrayindex++]=first[index1++];
    }
    else{
      arr[mainarrayindex++]=second[index2++];
    }
  }
  while(index1<len1){
    arr[mainarrayindex++]=first[index1++];
  }
  while(index2<len2){
    arr[mainarrayindex++]=second[index2++];
  }
  delete []first;
  delete []second;
}

void mergesort(int *arr,int s, int e){
  //base case
  if(s>=e){
    return;
  }
  int mid = s+(e-s)/2;
  //left part sort
  mergesort(arr,s,mid);
  //right part sort
  mergesort(arr,mid+1,e);
  //merge
  merge(arr,s,e);
}

int main(){
  int arr[20]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
  int n = 20;

  mergesort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;

  return 0;
}