#include <bits/stdc++.h>
using namespace std;
int main(){

    string s; 
    cout<<"Nhap xau: "; getline(cin,s);
    
    int nguyenAm = 0, phuAm = 0 , khac = 0;

    for(char c : s){
        if(isalpha(c)){
            char ch = tolower(c);
            if(ch=='u' || ch=='e'||ch=='a'||ch=='o'||ch=='i') nguyenAm++;
            else phuAm++;
        }else{
            khac++;
        }
    }

    cout<<"Nguyen am: "<<nguyenAm<<endl;
    cout<<"Phu am: "<<phuAm<<endl;
    cout<<"Ky tu khac: "<<khac<<endl;
}