#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int graph_size = graph.size();
        vector<int> color(graph_size, -1);
        color[0] = 0;
        for(int i=0; i<graph_size; i++){
             
            for(auto point:graph[i]){
                cout<<"check edge"<<i<<" "<<point<<endl;
                // color
                if(color[point] == -1){
                    color[point] = verse(color[i]);
                }
                    
                else{
                    if(color[i] == -1)
                        color[i] = verse(color[point]);

                    if(color[point] != verse(color[i]))
                        return false;
                }
            }

        }
        return true;
    }
    int verse(int color){
        if(color == 0)
            return 1;
        else
            return 0;
    }
};
int main(){
    // vector<vector<int>> graph= {{1,3}, {0,2}, {1,3}, {0,2}};
    // vector<vector<int>> graph= {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    vector<vector<int>> graph= {{4},{},{4},{4},{0,2,3}};
    cout<<Solution().isBipartite(graph)<<endl;
}
