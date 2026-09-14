#include<iostream>
#include<cmath>

using namespace std;

bool isCP(int n){
	int x = sqrt(n);
	return x*x==n;
}

void inputN(int &n){
    do{
        cout<<"So phan tu n = "; cin>>n;
    }while(n <= 0 || n >= 20);
}

int maxArray(int n,int *a){
    int max = *a;
    for(int i = 0;i < n;i++){
        if(max<*(a + i)) max=*(a + i);
    }
    return max;
}

int maxCP(int n,int *a){
    int max = *a;
    for(int i = 0;i < n;i++){
        if(max < *(a + i) && isCP(*(a + i))) max = *(a + i);
    }
    return max;
}

void inputArray(int n,int *a){
    for(int i = 0;i < n;i++){
		cout<<"Phan tu thu "<<i+1<<": "; cin>>*(a + i);
	}
}

void outputArray(int n,int *a){
    for(int i = 0;i < n;i++){
		cout<<" "<<*(a + i);
	}
}

int main()
{
	int n,*a;
    a = new int[100];
	inputN(n);
	inputArray(n,a);
	cout<<endl<<"In day so:";
	outputArray(n,a);
	cout<<endl<<"So max = "<<maxArray(n,a);
	cout<<endl<<"So chinh phuong lon nhat: "<<maxCP(n,a);
	return 0;
}
