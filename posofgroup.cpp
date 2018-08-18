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
        int start=0;
        for(int i=0; i< len; i++){
            if(i == len-1 || S[i] != S[i+1]){
                if(i-start+1 >= 3){
                    group.push_back({start, i});
                }
                start = i+1;
            }
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
    string s = "abcdddeeeeaabbb";
    vector<vector<int>> result = Solution().largeGroupPositions(s);
}
