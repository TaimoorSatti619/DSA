#include <iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>&a,int n,vector<int>&b,int m){
    int i=n-1;
    int j=m-1;
    int carry=0;
    vector<int>ans;
    while(i>=0 && j>=0){
        int val1=a[i];
        int val2=b[j];
        int sum= val1+val2+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    // first case
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    //second case
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);
}


int main() {
    vector<int>v1={1,2,3,4};
    vector<int>v2={6};
    vector<int>ans=findArraySum(v1,v1.size(),v2,v2.size());
    for(int num : ans) {
        cout << num;
    }
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> findArraySum(vector<int>&a,int n, vector<int>&b,int m) {
//     int A = 0 , B = 0 ;
//     for(int i = 0 ; i < n ; i++){
//         A = A*10 + a[i];
//     }
//     for(int i = 0 ; i < m ; i++){
//         B = B*10 + b[i];
//     }
//     A= A + B;
//     vector<int> sum;
//     while(A > 0){
//         int mod = A % 10;
//         sum.push_back(mod);
//         A = A / 10 ;
//     }
//     reverse(sum.begin() , sum.end());
//     return sum;
// }
// int main(){
//     vector<int>v1={1,2,3,4};
//     vector<int>v2={6};
//     vector<int>ans=findArraySum(v1,v1.size(),v2,v2.size());
//     for(int num : ans) {
//         cout << num;
//     }
//     cout << endl;
// }
