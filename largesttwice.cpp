#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        int bigest = nums[0];
        int secondbig = nums[0];
        int index = -1;
        for(int i=1; i<len; i++){
            if(nums[i] > bigest){
                index = i;
                secondbig = bigest;
                bigest = nums[i];
            }
        }
        cout<<secondbig<<"  "<<bigest<<endl;
        if(secondbig*2 <= bigest)
            return index;
        else
            return -1;
    }
                
};
int main(){
    vector<int> n = {3,6,1,0};
    cout<<Solution().dominantIndex(n);
}
