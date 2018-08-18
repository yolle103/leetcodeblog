#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        int bigest = nums[0];
        int index = 0;
        //find the bigest
        for(int i=0; i<len; i++){
            if(nums[i] > bigest){
                index = i;
                bigest = nums[i];
            }
        }
        nums.erase(nums.begin()+index);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]*2 > bigest)
                return -1;
        }
        return index;
    }
                
};
int main(){
    vector<int> n = {1,0};
    cout<<Solution().dominantIndex(n);
}
