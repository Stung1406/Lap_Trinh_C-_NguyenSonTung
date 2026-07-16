#include<bits/stdc++.h>

using namespace std;

int main(){
    int d;
    vector<int> arr = {1,2,3,4,5};
    
    vector<int> tmp;

    cout<<"Nhap d: "; cin>>d;

    int i = 0;
    while(d-- && i < arr.size()){
        tmp.push_back(arr[i]);
        i++;
    }

    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << " ";
    }


    return 0;
}