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
            if(k!=0 && !st.empty())
                if(st.top()<number)
                    k--; 
                else
                    st.pop();
            st.push(number);
        }
        // pop out of the stack
        string result;
        while(!st.empty()){
            result = to_string(st.top()) + result;
            st.pop();
        }
        cout<<result<<endl;
        int ct=0;
        while(result[ct] == '0')
            ct++;
        return result.substr(ct, result.size()-ct);
    }

};
int main(){
    string s = "10200";
    cout<<Solution().removeKdigits(s, 1);
}
