#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Sort012(int arr[], int n) {

    int l = 0, r = n-1 , m = 0;

     while (m <= r) {
        if (arr[m] == 0) {
            swap(arr[l], arr[m]);
            l++;
            m++;
        } else if (arr[m] == 1) {
            m++;
        } else if (arr[m] == 2) {
            swap(arr[m], arr[r]);
            r--;
        }
    }

}

int main() {

    int arr[8] = {1,1,2,0,2,0,1,0};

    Sort012(arr, 8);
    printArray(arr, 8);


    return 0;
}


// USING SWITCH STATMENT
#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Sort012(int arr[], int n)
{
    int l = 0;
    int r = n - 1;
    int m = 0;


    while (m <= r) {
        switch (arr[m]) {
            
        //i the elemet is 0
        case 0:
            swap(arr[l++], arr[m++]);
            break;

        // If the element is 1 .
        case 1:
            m++;
            break;

        // If the element is 2
        case 2:
            swap(arr[m], arr[r--]);
            break;
        }
    }
}
int main() {

    int arr[8] = {1,1,2,0,2,0,1,0};

    Sort012(arr, 8);
    printArray(arr, 8);


    return 0;
}
