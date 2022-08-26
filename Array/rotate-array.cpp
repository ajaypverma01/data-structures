#include <iostream>

using namespace std;

void rotateArray(int a[],int n){
    int temp;
    temp = a[0];
    for (int i = 0; i < n; i++) {
       a[i]=a[i+1];
    }
    a[n-1] = temp;
}

int main()
{
    cout<<"Rotate an array of integer by d elements"<<endl;
    int a[]={1,2,3,4,5,6};
    
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"enter the value of d:"<<endl;
    int d;
    cin>>d;
    
    for (int i = 0; i < d; i++) {
        rotateArray(a,n);
    }
    //print the array
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}