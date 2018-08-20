#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
#include<map>
using namespace std;
class Solution {
public:
    map<string, int> count_word(string A){
        map<string, int> hash_table;
        istringstream iss(A);
        vector<string> a((istream_iterator<string>(iss)), istream_iterator<string>());
        map<string, int>::iterator it;
        for(auto s: a)
            if((it = hash_table.find(s)) != hash_table.end())
                hash_table[s] += 1;
            else
                hash_table[s] = 1;
        return hash_table;
    
    }
    vector<string> uncommonFromSentences(string A, string B) {
        auto a = count_word(A + " " + B);
        vector<string> uncommon;
        map<string, int>::iterator it;
        for(auto word: a){
            if(word.second == 1)
                uncommon.push_back(word.first);
        }
        return uncommon;
    }
};
int main(){
    string A = "apple apple", B = "banana";
    vector<string> solution = Solution().uncommonFromSentences(A, B);
    for(auto s: solution)
        cout<<s<<"  ";
}
