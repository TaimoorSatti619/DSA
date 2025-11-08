#include<iostream>
using namespace std;

/*{
    int n;
    cin>>n;

    do{
        cout<<n<<endl;
        cin>>n;
    }
    while(n>0);
    return 0;
}

/*{
    for(int n=1;n<=100;n++)
    {
        if(n%3==0){
        continue;
        }
        cout<<n<<endl;
    }
        return 0;

}


/*{
    int row,col;
    cin>>row>>col;

    for(int n=1;n<=row;n++){
            for(int m=1;m<=col;m++){
                if(n==1 || n==row){
                    cout<<"*";
                }
                else if(m==1 || m==col){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;

    }
    return 0;
}*/


/*
    void print(int num){
        cout<<num<<endl;
        return;
    }
    
    int add(int num1,int num2){
        print(num1);
        print(num2);
        int sum= num1+num2;
        return sum;
    }
    int main()
    {
        int a=2;
        int b=3;
        cout<<add(a,b)<<endl;
        return 0;
    }*/


   /*int main(){
    int arr[10],n,max,min;
    for(n=0;n<10;n++){
        cout<<"enter numbers";
        cin>>arr[n];
    }
    max=arr[0];
    min=arr[0];
    for(n=0;n<10;n++){
        if(arr[n]>max){
            max=arr[n];
        }
        if(arr[n]<min){
            min=arr[n];
        }
    }
    cout<<"maximum number is:"<<max<<endl;
    cout<<"minimum number is:"<<min<<endl;

    return 0;
   }




