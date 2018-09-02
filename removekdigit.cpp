#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(int i=0; i<num.size(); i++){
            int number = (int)(num[i] - '0');
            while(!st.empty() && st.top()> number && k>0){
                    k--;
                    st.pop();
            }
            st.push(number);
        }
        // pop out of the stack
        string result;
        int count =0;
        while(!st.empty()){
            result = to_string(st.top()) + result;
            st.pop();
            count++;
        }
        cout<<result<<endl;
        int ct=0;
        while(result[ct] == '0')
            ct++;
        result = result.substr(ct, result.size()-ct);
        
        return result.substr(0, num.size()-k);
    }

};
int main(){
    string s = "112";
    cout<<Solution().removeKdigits(s, 1);
}
