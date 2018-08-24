#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    int product(vector<int> & num, int st, int ed){
        int pro=1;
        for(int i=st; i<=ed; i++){
            pro *= num[i];
        }
        return pro;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0, end=0;
        int count = 0;
        int pro;
        for(;end<nums.size(); end++){
            pro *= nums[end];
            while(start<=end && pro >=k){
                pro /= nums[start];
                start++;
            }
            count += (end-start+1);
        }
        return count;
    }
};
int main(){
    vector<int> ts = {10, 5, 2, 6, 7, 3};
    cout<<Solution().numSubarrayProductLessThanK(ts, 100);
}
