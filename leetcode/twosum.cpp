#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int complement = target-nums[i];
            if(mp.count(complement)){
                return{mp[complement],i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};

int main()
{
    vector<int> v = {2,15,8,7};
    int target = 9;
    vector<int> t = Solution().twoSum(v,target);
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }   
    return 0;
}