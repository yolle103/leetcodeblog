#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int> s1, s2;
        for(int i=0; i<S.size(); i++){
            if(S[i] != '#')
                s1.push(S[i]);
            else{
                if(!s1.empty())
                    s1.pop();
            }
        }
        for(int i=0; i<T.size(); i++){
            if(T[i] != '#')
                s2.push(T[i]);
            else{
                if(!s2.empty())
                    s2.pop();
            }
        }
        if(s1.size() != s2.size())
            return false;
        else{
            while(!s1.empty()){
                if(s1.top() != s2.top())
                    return false;
                s1.pop();
                s2.pop();
            }
            return true;
        }
            
    }
};
int main(){
    string a="ab##", b="c#d#";
    cout<<Solution().backspaceCompare(a, b)<<endl;
}
