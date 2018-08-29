#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int count = countlength(S);
        for(int i=S.size()-1; i>=0; i--){
            if(K % count != 0){
                if(isdigit(S[i])){
                    count /= (int)(S[i] - '0');
                }
                else
                    count--;
            }
            else
                return string(1, S[i]);
        }
    }
    int countlength(string S){
        int count=0;
        for(int i=0; i<S.size(); i++){
            if(isdigit(S[i])){
                count *= (int)(S[i] - '0');
            }
            else
                count += 1;
        }
        return count;
    }
};
int main(){
    string s = "leet2code3";
    cout<<Solution().decodeAtIndex(s, 11);
}
