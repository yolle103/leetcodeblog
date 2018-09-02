#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomnumber = rooms.size();
        cout<<roomnumber<<endl;
        vector<int> visit(roomnumber, 0);
        vector<int> temp;
        for(auto k : rooms[0])
            temp.push_back(k);
        visit[0] = 1;
        while(temp.size()!= 0){
            int cur = temp.back();
            visit[cur] = 1;
            temp.pop_back();
            for(auto k: rooms[cur]){
                if(visit[k] == 0) 
                    temp.push_back(k);
            }
        }
        for(auto k: visit){
            if(k == 0)
                return false;
        }
        return true;
    }

};
int main(){
    // vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    cout<<Solution().canVisitAllRooms(rooms);
}
