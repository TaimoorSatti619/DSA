#include<iostream>
#include<stack>
#include<string>
using namespace std;

/// VALID PARENTHESIS

bool isValid(string str){

    stack<char>st;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){  // opening
            st.push(str[i]);
        }
        else{ // closing
            if(st.size() == 0){
                return false;
            }

            if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']')){
                st.pop();
            }
            else{  // no match
                return false;
            }
        }
    }
    return st.size() == 0;
}

//********************************************************************************************************************** 

int main(){
    string str = "({[]})";
    if(isValid(str)){
        cout<<"VALID";
    }
    else{
        cout<<"INVALID";
    }

    return 0;
}