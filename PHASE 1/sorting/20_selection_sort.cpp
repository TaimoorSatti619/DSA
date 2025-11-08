#include <iostream>
using namespace std;

int main() 
{
  int i;
  cout<<"ENTER ARRAY NO :";
  cin>>i;
  int arr[i],n,m,temp;
  for(n=0;n<i;n++)
  {
  cout<<"enter numbers :";
  cin>>arr[n];
  }
  cout<<"the original valurs are"<<endl;
  for(n=0;n<i;n++)
  cout<<arr[n]<<" ";
  
  for(n=0;n<i-1;n++)
    
    for(m=n+1;m<i;m++){
      
    if(arr[m]<arr[n]){
      
      temp=arr[m];
      arr[m]=arr[n];
      arr[n]=temp;
    }
    
    }
    cout<<endl<<"the sorted array is"<<endl;
    for(n=0;n<i;n++)
    cout<<arr[n]<<" ";
    
    return 0;
}