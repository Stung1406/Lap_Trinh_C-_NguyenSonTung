#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int hourglassSum(vector<vector<int>> arr) {
    vector<vector<int>> sums(4, vector<int>(4, 0));
    for (int i = 0;i<=3;i++){
        for(int j = 0;j<=3;j++){
                 sums[i][j] = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j] +arr[i+2][j+1]+arr[i+2][j+2];
            }
        }
    int max = sums[0][0];
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(max<sums[i][j]) max=sums[i][j];        
        }
    }
    return max;
}
};

int main()
{
    vector<vector<int>> arr;

    return 0;
}
