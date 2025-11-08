#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

int main(){

    vector<int>arr = {6,8,0,1,3};

    /// NEXT GREATER ELEMENT               TC -O(n)
                                        // SC -O(n)
    stack<int>s; 
    vector<int>ans(arr.size(),0);

    for(int i = arr.size()-1; i >= 0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    // print ans
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}



///**************************************************************************************************

/// NEXT GREATER ELEMENT I

vector<int>nextGreaterElement(vector<int>& nums1,vector<int>& nums2){
    unordered_map<int,int>m;
    stack<int>s;

    for(int i = nums2.size()-1; i >= 0; i--){
        while(s.size() > 0 && s.top() <= nums2[i]){
            s.pop();
        }
        if(s.empty()){
            m[nums2[i]] = -1;
        }
        else{
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }

    vector<int>ans;
    for(int i = 0; i < nums1.size(); i++){
        ans.push_back(m[nums1[i]]);
    }

    return ans;
}

//***************************************************************************************************************