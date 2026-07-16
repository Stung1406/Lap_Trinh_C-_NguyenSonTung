#include<bits/stdc++.h>
using namespace std;

int tinhTong(int n){
    int S=0;
    string s = to_string(n);
    for(int i=0;i<s.size();i++){
        S += s[i] - '0';
    }
    return S;
}

int main()
{
    int n;
    cin>>n;
    cout<<"/nTong cac chu so cua "<<n<<" la: "<<tinhTong(n);
    return 0;
}