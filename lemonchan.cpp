#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int do5 = 0;
        int do10 = 0;
        int do20 = 0;
        int len = bills.size();
        for(int i=0; i<len; i++){
            if(bills[i] == 5)
                do5 += 1;
            if(bills[i] == 10)
                do5 -= 1;
            if(bills[i] == 20){
                if(do10 > 0)
                    do10 -= 1;
                else
                    do5 -=2;
            }
            if(do5<0)
                return false;
        }
        return true;
    }
};
int main(){
    vector<int> ve = {5,5,10,10,20};
    cout<<Solution().lemonadeChange(ve)<<endl;

}
