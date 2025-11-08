#include <iostream>
using namespace std;

int main() 
{
  int i;
  cout<<"ENTER ARRAY SIZE :";
  cin>>i;
  int arr[i],n,m,temp;
  for(n=0;n<i;n++)
  {
  cout<<"enter elements : ";
  cin>>arr[n];
  }
  cout<<"the original valurs are"<<endl;
  for(n=0;n<i;n++)
  cout<<arr[n]<<" ";
  for(n=0;n<i;n++){
    
    for(m=0;m<i-1;m++)
    if(arr[m]>arr[m+1]){
      
      temp=arr[m];
      arr[m]=arr[m+1];
      arr[m+1]=temp;
    }
    
    }
    cout<<endl<<"the sorted array is"<<endl;
    for(n=0;n<i;n++)
    cout<<arr[n]<<" ";
    
    return 0;
}