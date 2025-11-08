#include <iostream>
using namespace std;

  char toLowerCase(char ch) {
    if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

void reverse(char name[], int n){
    int s=0;
    int e =n-1;
    while(s<=e){
        swap(name[s++],name[e--]);
    }
}

int getlength(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

bool check(char name[], int n){
    int s=0;
    int e =n-1;
    while(s<=e){
        if(toLowerCase(name[s])!=toLowerCase(name[e]))
        return 0;
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int main() {
    char name[20];
    cout<<"enter your name"<<endl;
    cin>>name;

    cout<<"your name is :";
    cout<<name<<endl;
    
    int len=getlength(name);
    cout<<"length of name is :"<<len<<endl;
    
    reverse(name,len);
    cout<<"your name is :";
    cout<<name<<endl;
    
    if(check(name,len)){
        cout<<"palindrome";
    }
    else{
        cout<<"not a palindrome";
    }
    cout<<endl;
    
    cout<<"character is "<<toLowerCase('B')<<endl;

    return 0;
}