#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*
/// STACK IMPLEMENTATION USING VECTOR
class Stack{
    vector<int>v;

 public:

    void push(int val){ //O(1)
        v.push_back(val);
    }

    void pop(){  //O(1)
        v.pop_back();
    }

    int top(){  //O(1)
        return v[v.size()-1];
    }

    bool empty(){  //O(1)
        return v.size() == 0;
    }

};
*/

//************************************************************************************************************

/// STACK IMPLEMENTATION USING LINK LIST
class Stack{
    list<int>ll;

 public:

    void push(int val){ //O(1)
        ll.push_front(val);
    }

    void pop(){  //O(1)
        ll.pop_front();
    }

    int top(){  //O(1)
        return ll.front();
    }

    bool empty(){  //O(1)
        return ll.size() == 0;
    }

};

//************************************************************************************************************

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
