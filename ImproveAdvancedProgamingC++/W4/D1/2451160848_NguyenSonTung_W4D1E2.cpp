#include<iostream>
#include<string>

using namespace std;

struct Sach{
    string tenSach;
    int giaSach;
};

Sach inputSach(Sach s){
    cout<<"Ten: "; cin>>s.tenSach;
    cout<<"Gia: "; cin>>s.giaSach;
    return s;
}


Sach *inputArr(int n,Sach *s){
    s = new Sach[100];
    for(int i=0;i<n;i++){
        *(s + i) = inputSach( *(s + i) );
    }
    return s;
}

void outputArr(int n,Sach *&s){
    for(int i=0;i<n;i++){
        cout<<(s + i)->tenSach<<"\t"<<(s+i)->giaSach<<endl;
    }
}

int main()
{
    int n;
    Sach *s;
    cout<<"N = "; cin>>n;
    
    if(n==0) cout<<"DS ban dau rong!";
    else
    {
        inputArr(n,s);
        n--;
        if(n==0) cout<<"DS da rong!";
        else
        {
            cout<<"Ket qua:"<<endl;
            outputArr(n,s);
        }
    }
    delete [] s;
    return 0;
}