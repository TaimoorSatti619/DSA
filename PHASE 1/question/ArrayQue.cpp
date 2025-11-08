#include <iostream>
using namespace std;
//MAX/MIN PROGRAM

int Max(int arr[],int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int Min(int arr[],int n){
    int min = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
int main() {
    int size;
    cin>>size;
    int arr[100];
// for input
for(int i = 0;i<size;i++){
    cin>>arr[i];
}
// for printing
cout<<"maximum is :"<<Max(arr,size)<<endl;
cout<<"minimum is :"<<Min(arr,size)<<endl;

    return 0;
}
 // SUM OF THE ARRAY PROGRAM
#include <iostream>
using namespace std;
int Sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}
int main(){
    int size;
    cin>>size;
    int arr[100];
    //for input
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //for output
   /* int sum=0;
    for(int i=0;i<size;i++){
        sum=sum+arr[i];
    }*/
    cout<<"sum of array is :"<<Sum(arr,size);
    
}

//LINEAR SEARCH
#include <iostream>
using namespace std;
bool search(int arr[],int size ,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[5]={1,3,5,2,4};
    int key;
    cout<<"enter a element to search for :";
    cin>>key;
    
    bool found=search(arr,5,key);
    if(found){
        cout<<"element is present";
    }
    else{
       cout<<"element is not present"; 
    }
}

//REVERSE AN ARRAY
#include <iostream>
using namespace std;

void reverse(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int size;
    cin>>size;
    int arr[100];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    reverse(arr,size);
    printArray(arr,size);
    
    return 0;
}