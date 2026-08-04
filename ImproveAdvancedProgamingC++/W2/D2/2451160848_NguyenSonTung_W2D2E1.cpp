#include<iostream>

using namespace std;


int *inputArray(int *a,int n){
    a = new int[100];
    for(int i=0;i<n;i++){
        cout<<"a["<<i+1<<"] = "; 
        cin >> *(a+i);
    }
    return a;
}

int dem100(int *a,int n){
    int dem=0;
    for(int i=0;i<n;i++)
        if(100 % *(a+i) == 0  ) dem++;
    
    return dem;
}

void printIndex(int *a,int n){
    for(int i=0;i<n;i++)
        if(100 % *(a+i) == 0  ) cout<<" "<<i+1;
}

int main()
{
    int *a,n;
    cout<<"N = "; cin>>n;
    a = inputArray(a,n);
    if(dem100(a,n) == 0) cout<<"Khong co so nao";
    else
    {
        cout<<"KQ:";
        printIndex(a,n);
    }
    delete a;
    return 0;
}