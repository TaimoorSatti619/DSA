// #include <iostream>
// #include <vector>
// using namespace std;

// void rotate(vector<int>&nums,int k){
//     vector<int>temp(nums.size());
//     for(int i=0;i<nums.size();i++){
//         temp[(i+k)%nums.size()]=nums[i];
//     }
//     nums = temp;
// }
// void print(vector<int>&nums){
//     for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<" ";
//     }cout<<endl;
// }
// int main() {
//     vector<int>n={1,2,3,4,5};
//     int k=1;
//     rotate(n,k);
//     print(n);
//     return 0;
// }



#include <iostream>
using namespace std;

void rotate(int arr[],int n,int k){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
    for(int i =0;i<n;i++){
        arr[i]=temp[i];
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main() {
    int arr[5]={1,2,3,4,5};
    int k=2;
    rotate(arr,5,k);
    print(arr,5);
    return 0;
}