#include<iostream>

using namespace std;

int *inputArr(int n,int *a){
    a = new int[100];
    for(int i = 0;i < n; i++){
        cout<<"a["<<i<<"] = "; cin>> *(a + i);
    }
    return a;
}

int main()
{
    int n,*a;
    return 0;
}