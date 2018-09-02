#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long count = countlength(S);
        for(int i=S.size()-1; i>=0; i--){
            K %= count;
            if(K == 0 && isalpha(S[i]))
                return (string)"" + S[i];
            if(!isdigit(S[i]))
                count--;
            else
                count /= (int)(S[i] - '0');
        }
    }
    long countlength(string S){
        long count=0;
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
    string s = "ixm5xmgo78";
    cout<<Solution().decodeAtIndex(s, 711);
}
