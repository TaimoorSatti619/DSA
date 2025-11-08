#include<iostream>
using namespace std;

// <- INVERSION COUNT  ->

int merge(int *arr,int s,int e){
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
  int inversioncount = 0;

  while(index1<len1 && index2<len2){
    if(first[index1]<=second[index2]){
      arr[mainarrayindex++]=first[index1++];
    }
    else{
      arr[mainarrayindex++]=second[index2++];
      inversioncount += len1 - index1;
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
  return inversioncount;
}

int mergesort(int *arr,int s, int e){
  //base case
  if(s>=e){
    return 0;
  }
  int mid = s+(e-s)/2;
  //left part sort
  int inversioncount = mergesort(arr,s,mid);
  //right part sort
  inversioncount += mergesort(arr,mid+1,e);
  //merge
  inversioncount += merge(arr,s,e);
  return inversioncount;
}

int main(){
  int arr[4]={8,4,2,1};
  int n = 4;

  cout<<mergesort(arr,0,n-1);
 /* for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;*/

  return 0;
}