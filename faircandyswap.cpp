#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = sumvector(A);
        int sumb = sumvector(B);
        int diff = (suma-sumb)/2;
        vector<int>::iterator it;
        for(auto a: A){
            int findnum = a-diff;
            cout<<diff<<"  "<<findnum<<endl;
            it = find(B.begin(), B.end(), findnum);
            if(it != B.end()){
                vector<int> result = {a, a-diff};
                return result;
            }
        }
    }
    int sumvector(vector<int> &A){
        int sum = 0;
        for(auto i: A)
            sum += i;
        return sum;
    }

};
int main(){
    vector<int> A = {1,2,5};
    vector<int> B = {2,4};
    auto re = Solution().fairCandySwap(A, B);
    for(auto r:re)
        cout<<r<<"  "<<endl;
}
