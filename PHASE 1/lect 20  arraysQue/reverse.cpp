#include <iostream>
#include <vector>

using namespace std;
vector<int>reverse(vector<int>v){     // kabhi kis number kay baad reverse karna ha tu int m;
    int s =0;               // s = m+1; hu jahey ga
    int e = v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
int main() {
    vector<int>v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
                                                // idr int m= ju bhi number hua;
    vector<int> ans=reverse(v);                 // idr (v,m)
    print(ans);
    
    return 0;
}