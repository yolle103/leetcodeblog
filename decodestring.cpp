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
            if(count == 0)
                return string(1, S[0]);
            if(K % count != 0){
                if(isdigit(S[i])){
                    count /= (int)(S[i] - '0');
                }
                else
                    count--;
            }
            else{
                if(!isdigit(S[i]))
                    return string(1, S[i]);
                else{
                    count /= (int)(S[i] - '0');
                }
            }
            K %= count;
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
    string s = "ixm5xmgo78";
    cout<<Solution().decodeAtIndex(s, 711);
}
