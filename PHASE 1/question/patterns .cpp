#include <iostream>
using namespace std;

int main() {
    // PATERN 1
    
   /* int n;
    cin>>n;
    int i=1;                            
    while(i<=n){
        int j =1;
        while(j<=n){
            cout<<n-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // PATERN 2
    
   /* int n;
    cin>>n;
    int i =1;
    int count =1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout<<count<<"  ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
        
    }*/

    // PATERN 3
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        while(j<=i){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 4
    
    /*int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 5
    
    /*int n;
    cin>>n;
    int i =1;
    int c = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<c<<" ";
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }*/
     // PATERN 6
    
  /*  int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        int v =i;
        while(j<=i){
            cout<<v<<" ";
            v++;
            j++;
        }
        cout<<endl;
        i++;
    }
    int main() {
     int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        while(j<=i){
            cout<<i+j-1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
        
    }*/
    // PATERN 7
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        while(j<=i){
            cout<<i-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 8
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        while(j<=n){
            char c ='A'+i-1;
            cout<<c<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 9
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        while(j<=n){
            char c ='A'+j-1;
            cout<<c<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 10
    
    /*int n;
    cin>>n;
    int i =1;
    char c = 'A';
    while(i<=n){
        int j =1;
        while(j<=n){
            cout<<c<<" ";
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 11
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            char c = 'A'+i+j-2;
            cout<<c<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
     // PATERN 12
    
    /*int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            char c ='A'+i-1;
            cout<<c<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 13
    
    /*int n;
    cin>>n;
    int i =1;
    char c = 'A';
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<c<<" ";
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }*/
    // PATERN 14
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            char c = 'A'+i+j-2;
            cout<<c<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/
      // PATERN 15
    
    /*int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j = 1;
        char c = 'A'+n-i;
        while(j<=i){
            cout<<c<<" ";
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }*/
     // PATERN 16
    
   /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int s=n-i;
        while(s){
            cout<<" ";
            s--;
        }
        int j =1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }*/
      // PATERN 17
    
    /*int n;
    cin>>n;
    int i =n;
    while(i>=1){
        int j=1;
        while(j<=i){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i--;
    }*/
    // PATERN 18
    
  /* int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int s=i-1;
        while(s){
            cout<<" ";
            s--;
        }
            int t=n-i+1;
            while(t){
            cout<<"*";
            t--;
        }
        cout<<endl;
        i++;
    }*/
     // PATERN 19
    
   /*int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int s=i-1;
        while(s){
            cout<<" ";
            s--;
        }
            int t=n-i+1;
            while(t){
            cout<<i;
            t--;
        }
        cout<<endl;
        i++;
    }*/
     // PATERN 20
    // still working
   /*int n;
    cin>>n;
    int i =n;
    while(i>=1){
        int s=n-i;
        while(s){
            cout<<" ";
            s--;
        }
            int t=n-i+1;
            while(t){
            cout<<i;
            t--;
        }
        cout<<endl;
        i--;
    }*/
   // PATERN 21
    
   int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int s =n-i;
        while(s){
            cout<<" ";
            s--;
        }
        int j =1;
        while(j<=i){
            cout<<j;
            j++;
        }
        int t=i-1;
        while(t){
            cout<<t;
            t--;
        }
        
        cout<<endl;
        i++;
    }
        
        


    return 0;
}