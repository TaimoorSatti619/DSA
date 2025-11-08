#include<iostream>
#include<stack>
using namespace std;
/*
class MinStack{    // TC--> O(1)       SC--> O(2*n)
    public:
    stack<pair<int,int>>s;

    MinStack(){

    }

    // push element
    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }
        else{
            int minVal = min(val,s.top().second);
            s.push({val,minVal});
        }
    }

    // pop element
    void pop(){
        s.pop();
    }

    // top wala element
    int top(){
        return s.top().first;
    }

    // min wala element
    int getMin(){
        return s.top().second;
    }
};
*/
//************************************************************************************************

class MinStack{  // TC--> O(1)       SC--> O(n)
    public:
    stack<long long int>s;
    long long int minVal;

    MinStack(){

    }

    // push element
    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal = val;
        }
        else{
            if(val < minVal){
                s.push((long long)2*val - minVal);
                minVal = val;
            }
            else{
                s.push(val);
            }
        }
    }

    // pop element
    void pop(){
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }

    // top wala element
    int top(){
        if(s.top() < minVal){
            return minVal;
        }
        return s.top();
    }

    // min wala element
    int getMin(){
        return minVal;
    }
};



int main(){
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-4);
    ms.push(5);
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;

    return 0;
}
