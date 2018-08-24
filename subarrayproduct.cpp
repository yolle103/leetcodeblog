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
        while(start<nums.size()){

            while(product(nums, start, end)<k && end<nums.size()){
                count++;
                end++;
            }
            if(product(nums, start, end) >=k || end == nums.size()){
                start++; 
                end = start;
            }

        }
        return count;
    }
};
int main(){
    vector<int> ts = {10, 5, 2, 6};
    cout<<Solution().numSubarrayProductLessThanK(ts, 100);
}
