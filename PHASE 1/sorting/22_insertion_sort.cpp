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
  cout<<"the original values are"<<endl;
  for(n=0;n<i;n++)
  cout<<arr[n]<<" ";
  
  //condition starting
  for(n=1;n<i;n++)
{
    temp=arr[n];
    m=n-1;
    while(arr[m]>temp && m>=0)
    {
        arr[m+1]=arr[m];
        m--;
    }
    arr[m+1]=temp;
}
    
    // THE sorted Array
    cout<<endl<<"the sorted array is"<<endl;
    
    for(n=0;n<i;n++)
    cout<<arr[n]<<" ";
    
    return 0;
}