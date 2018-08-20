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
            if((it = hash_table.find(a[1])) != hash_table.end())
                hash_table[a[1]] += stoi(a[0]);
            else
                hash_table[a[1]] = stoi(a[0]);
            cout<<a[1]<<"--------"<<stoi(a[0])<<endl;

            // extract sub domains
            string origindomain = a[1];
            istringstream sub(a[1]);
            vector<string> tokens;
            string token;
            while(getline(sub, token, '.')){
                if(!token.empty())
                    tokens.push_back(token);
            }
            for(int j=1; j<tokens.size(); j++){
                string sub_domain = tokens[j];
                for(int k=j+1; k<tokens.size(); k++){
                    sub_domain += "." + tokens[k];
                }
                if((it = hash_table.find(sub_domain)) != hash_table.end()){
                    hash_table[sub_domain] += stoi(a[0]);
                }
                else
                    hash_table[sub_domain] = stoi(a[0]);
            }
            cout<<hash_table["ca"]<<endl;
        }
        vector<string> result;
        for(auto k : hash_table){
            result.push_back(to_string(k.second)+" "+k.first);
        }
        return result;
            
    }
};
int main(){
    vector<string> cpdomains = {
    "654 yaw.lmm.ca" ,
    "1501 ara.ca",
    "1225 lmm.ca",
    "7193 xth.fzx.ca",
    "1789 xcf.zqy.ca",
    "1627 bhp.ca",
    "2913 ret.ych.ca",
    "9219 tfm.ca",
    "8176 ujm.gqs.ca",
    "1873 kse.gjf.ca"};
    auto re = Solution().subdomainVisits(cpdomains);
    for(auto r: re)
        cout<<r<<endl;
}
