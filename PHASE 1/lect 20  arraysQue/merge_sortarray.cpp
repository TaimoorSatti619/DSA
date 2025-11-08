// #include <iostream>
// #include <vector>
// using namespace std;

// void merge(int arr1[],int n,int arr2[],int m,int arr3[]){
//     int i =0,j =0,k=0;
//     while(i<n && j<m){
//         if(arr1[i]<arr2[j]){
//             arr3[k++]=arr1[i++];
//         }
//         else{
//             arr3[k++]=arr2[j++];
//         }
//     }
//     while(i<n){
//         arr3[k++]=arr1[i++];
//     }
//     while(j<m){
//          arr3[k++]=arr2[j++];
//     }
// }
// void print(int ans[],int n){
//     for(int i =0;i<n;i++){
//         cout<<ans[i]<<" ";
//     }cout<<endl;
// }
// int main() {
//     int arr1[5]={1,3,5,7,9};
//     int arr2[4]={2,4,6,8};
//     int arr3[9]={0};
    
//     merge(arr1,5,arr2,4,arr3);
//     print(arr3,9);
    
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    vector<int> ans;  // Initialize ans as a new vector
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    // Add the remaining elements of arr1 (if any)
    while (i < n) {
        ans.push_back(arr1[i]);
        i++;
    }
    // Add the remaining elements of arr2 (if any)
    while (j < m) {
        ans.push_back(arr2[j]);
        j++;
    }
    arr1 = ans;  // Update arr1 to be the merged result
}

void print(const vector<int>& ans) {  // Adapted to work with vectors
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 5, 6};
    merge(arr1, 3, arr2, 3);
    print(arr1);  // This will now print the merged vector
}
