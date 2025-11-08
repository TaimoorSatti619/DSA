#include<iostream>
using namespace std;

/*void reverse(string& s,int i,int j){   // for one pointer use this
  //base case                          // int j = s.length()-i-1;
  if(i>j){
    return;
  }
  swap(s[i],s[j]);
  i++;
  j--;
  //recursive call
  reverse(s,i,j);
}

int main(){
  string s = "taimoor";
  reverse(s,0,s.length()-1);
  cout<<s;
}*/

//<-CHECK PALINDROME->

/*bool checkpalindrome(string& s,int i,int j){   // for one pointer use this
  //base case                                  //  int j = s.length()-i-1;
  if(i>j){
    return true;
  }
  if(s[i]!=s[j]){
    return false;
  }
  else{
    return checkpalindrome(s,i+1,j-1);
  }
}

int main(){
  string s = "talat";
  bool ans = checkpalindrome(s,0,s.length()-1);
  if(ans){
    cout<<"yes";
  }
  else{
    cout<<"no";
  }
}*/

// <-POWER->

/*int power(int a, int b){
  //base case
  if(b==0){
    return 1;
  }
  if(b==1){
    return a;
  }
  //recursive call
  int ans = power(a,b/2);
  
  if(b%2==0){
    return ans * ans;
  }
  else{
    return a * ans * ans;
  }
}

int main(){
  int a , b;
  cin>> a >> b;
  int ans = power(a,b);
  cout<<ans;
}*/

// <- BUBBLE SORT ->

void sortArray(int *arr , int n){
  //base case
  if(n==0 || n==1){
    return;
  }
  for(int i =0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      swap(arr[i],arr[i+1]);
    }
  }
  //recursive call
  sortArray(arr,n-1);
}

int main(){
  int arr[5]= {1,3,5,2,4};
  sortArray(arr ,5);
  for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}