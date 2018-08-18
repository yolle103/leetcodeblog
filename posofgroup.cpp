#include<map>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int len = S.size();
        vector<vector<int>> group;
        char cur = S[0];
        int groupcount = 1;
        int start=0, end=-1;
        for(int i=1; i< len; i++){
            if(S[i] == cur){
                groupcount += 1;
                end = i;
            }
            else{
                if(groupcount >= 3){
                    vector<int> temp = {start, end};
                    group.push_back(temp);
                }
                groupcount = 1;
                start = i;
            }
            cur = S[i];
        }
        for(int i=0; i<group.size(); i++){
            for(int j=0; j<group[i].size(); j++)
                cout<<group[i][j]<<"   ";
            cout<<endl;
        }
        return group;

    }
};
int main(){
    string s = "abcdddeeeeaabbbcd";
    vector<vector<int>> result = Solution().largeGroupPositions(s);
}
