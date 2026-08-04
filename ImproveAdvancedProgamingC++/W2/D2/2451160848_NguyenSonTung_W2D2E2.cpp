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
    cout<<"K = "; cin>>k;
    if(k < 0 || k>=n) cout<<"Vi tri khong dung";
    else 
    {
        a = delIndexK(a,n,k);
        cout<<"KQ:"; outputArray(a,n);
    }
    delete a;
    return 0;
}