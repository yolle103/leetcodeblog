#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size()+1;
        vector<int> f(len);
        f[0] = 0;
        f[1] = 0;
        for(int i=2; i<len; i++){
            f[i] =  min(f[i-1]+cost[i-1], f[i-2]+cost[i-2]);
        }
        return f[len-1];
        
    }
};
int main(){
    vector<int> cost = {1, 100,1,1,100,1};
    cout<<Solution().minCostClimbingStairs(cost)<<endl;
}
