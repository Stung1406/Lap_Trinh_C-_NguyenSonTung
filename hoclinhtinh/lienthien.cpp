#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int x=17,y=3;
    // if(typeid(x)==typeid(y)) cout<<1;
    // else cout<<0;
    // cout<<endl;
    // double z = (1.0)*x/y;
    // cout<<z;
    // int n = 2,valudeProduced;
    // valudeProduced = 2 *(n++)
    // cout<<n<<endl;
    // int n = 2,valudeProduced;
    // valudeProduced = 2 *(++n)
    // cout<<n<<endl;
    //cerr : xuat loi
    // random 1 so trong khoan a,b [a,b] : x = a + rand()%(b-a+1)
    // int x = 3+rand()%18; 
    // cout<<x<<endl;
    // if(x<=10) cout<<"Xiu";
    // else cout<<"Tai";
    int x;
    srand(time(0));
    for(int i=0;i<10;i++){
        x=rand()%100;
        cout<<x<<" ";
    }
    cout<<x;
    return 0;
}

