#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    
    int maxDistToClosest2(vector<int>& seats) {
        int len = seats.size();
        int prev = -1, future = 0;
        int maxdis = -1;
        for(int i=0; i<len; i++){
            if(seats[i] == 1)
                prev = i;
            else
                while(future<i || (future<len && seats[future] == 0))
                    future += 1;
            int left, right;
            left = prev == -1? len : i-prev;
            right = future == 0? len : future-i;
            maxdis = max(maxdis, min(left, right));
        }
        return maxdis;
    }
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        int left[len], right[len];
        fill_n(left, len, len);
        fill_n(right, len, len);
        for(int i=0; i<len; i++){
            if(seats[i] == 1)
                left[i] = 0;
            else
                if(i>0)
                    left[i] = left[i-1] + 1;
        }
        for(int j=len-1; j>=0; j--){
            if(seats[j] == 1)
                right[j] = 0;
            else
                if(j<len-1)
                    right[j] = right[j+1] + 1;
        }
        // for(int j=0;j<len;j++)
        //     cout<<left[j]<<endl;
        // cout<<"-----------"<<endl;
        //
        // for(int j=0; j<len;j++)
        //     cout<<right[j]<<endl;
        int maxall = -1;
        for(int k=0; k<len; k++){
            // find max
            int cur_min = min(left[k], right[k]);
            if(cur_min > maxall)
                maxall = cur_min;
        }
        return maxall;
    }
            
};
int main(){
    vector<int> vec = {1,0,0,0};
    cout<<Solution().maxDistToClosest2(vec)<<endl;
}

