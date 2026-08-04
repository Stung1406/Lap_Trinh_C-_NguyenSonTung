#include<iostream>

using namespace std;

int *inputArray(int *a,int n){
    a = new int[100];
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"] = "; 
        cin>>*(a+i);
    }
    return a;
}

void outputArray(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<" "<<*(a + i);
    
}

double tinhTBC(int *a,int n){
    double sum=0;
    for(int i=0;i<n;i++){
        sum += *(a+i);
    }
    return sum/(1.0*n);
}

int minArray(int *a,int n){
    int min = *(a + 0);
    for(int i=0;i<n;i++){
        if(min < *(a+i)) min = *(a+i);
    }
    return min;
}

int *delIndexK(int *a,int &n,int k){
    for(int i=k;i<n;i++){
        *(a+i) = *(a+i+1);
    }
    n--;
    return a;
}

int main()
{
    int *a,n,k;
    cout<<"N = "; cin>>n;
    a = inputArray(a,n);
    
    delete a;
    return 0;
}