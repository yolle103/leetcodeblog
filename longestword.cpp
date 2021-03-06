#include<stdio.h>
#include<unordered_map>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string longest = "";
        for(auto s: words){
            int len = s.size();
            bool flag=true;
            for(int i=1;i<len;i++){
                string prefix = s.substr(0,i);
                if(find(words.begin(), words.end(), prefix) != words.end())
                   continue; 
                else{
                    flag=false;
                    break;
                }
            }
            if(flag && len > longest.size()){
                longest = s;
            }
        }          
        return longest;
    }
};
int main(){
    vector<string> test = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout<<Solution().longestWord(test)<<endl;
}
