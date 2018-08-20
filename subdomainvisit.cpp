#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
#include<stdio.h>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // first extract the origin domain& count
        unordered_map<string, int> hash_table;
        vector<string> origindomains;
        for(auto s:cpdomains){
            istringstream iss(s);
            unordered_map<string, int>::iterator it;
            vector<string> a((istream_iterator<string>(iss)), istream_iterator<string>());
            if((it = hash_table.find(a[1]) != hash_table.end()))
                hash_table[a[1]] += stoi(a[0]);
            else
                hash_table[a[1]] = stoi(a[0]);
            // extract sub domains
            string origindomain = a[1];
            istringstream sub(a[1]);
            vector<string> tokens;
            string token;
            while(getline(sub, token, '.')){
                if(!token.empty())
                    tokens.push_back(token);
            }
            int i=0,j=1;
            for(;j<tokens.size();j++){
                string sub_domain;
                for(int k=j; k<tokens.size(); k++){
                    if(sub_domain.size()>0)
                        sub_domain += ".";
                    sub_domain += tokens[k];
                }
                if((it = hash_table.find(sub_domain)) != hash_table.end()){
                    hash_table[sub_domain] += hash_table[origindomain];
                }
                else
                    hash_table[sub_domain] = stoi(a[0]);
            }
        }
        vector<string> result;
        for(auto k : hash_table){
            result.push_back(to_string(k.second)+" "+k.first);
        }
        return result;
            
    }
};
int main(){
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    auto re = Solution().subdomainVisits(cpdomains);
    for(auto r: re)
        cout<<r<<endl;
}
