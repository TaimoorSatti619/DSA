#include <iostream>
#include <climits>
using namespace std;

/*bool ispresent(int arr[][3],int key,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
    
}*/
// full sum
/*int sum(int arr[][3],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum=sum+arr[i][j];
        }
    }
    return sum;
}*/

// row wise sum
 void printRsum(int arr[][3],int n,int m){
     cout<<"Printing row wise sum->"<<endl;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
 }
//  coloum wise sum
 void printCsum(int arr[][3],int n,int m){
     cout<<"Printing coloumn wise sum->"<<endl;
    for(int j=0;j<3;j++){
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=arr[i][j];
        }
         cout<<sum<<" ";
    }
    cout<<endl;
 }
//largest sum
 int largestsum(int arr[][3],int n,int m){
    int maxi=INT_MIN;
     int rowindex=-1;
     for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex=i;
        }
    }
    cout<<"the maximum sum is"<<maxi<<endl;
    return rowindex;
 }

int main() {
    int arr[3][3];
    cout<<"enter elements"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"the elsements are"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
/*    cout<<"enter element to search"<<endl;
    int key;
    cin>>key;
    if(ispresent(arr,key,3,3)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }*/
/*    int ans =sum(arr,3,3);
    cout<<ans;*/
    printRsum(arr,3,3);
    printCsum(arr,3,3);

    int ans =largestsum(arr,3,3);
    cout<<"maxium sum is at index"<<ans;

    return 0;
}