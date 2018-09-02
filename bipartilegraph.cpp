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
                    if(color[i] == -1)
                        color[point] = 0;
                    else
                        color[point] = 1 - color[i];

                    cout<<"color"<<point<<"  "<<color[point]<<endl;
                }
                    
                else{
                    if(color[i] == -1)
                        color[i] = 1 - color[point];

                    if(color[point] != 1 - color[i])
                        return false;
                }
            }

        }
        return true;
    }
};
int main(){
    // vector<vector<int>> graph= {{1,3}, {0,2}, {1,3}, {0,2}};
    // vector<vector<int>> graph= {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    // vector<vector<int>> graph= {{4},{},{4},{4},{0,2,3}};
    vector<vector<int>> graph= {{51,58,98},{81,85},{50,62,63,85,94},{52,90,91,97,99},{63,74,97},{63,64,68,82},{50,61,89},{56,58,60,79,96},{57,65,82,92},{59,68,96},{89},{50,56,86,97},{65,71},{},{96,98},{61},{56,78},{59,61,74,92},{51,76},{56,71,77},{73},{76,87,89},{51,69,78},{57,68,74,93},{64,66,79},{53,59},{66},{53,72,80,97},{56,98},{73,83,91,94,95},{55,65,66,87},{52,69,76},{71,92},{74,82},{74,78,85,87,98},{87,99},{52,62,78},{66,68,83,97},{},{52,56,69,77,80},{55,73,77,86},{53,57,71,92},{82},{53,54,56,65,74,79},{99},{56,71,90},{},{57,85},{60,61},{50,57,59,77,78},{2,6,11,49},{0,18,22},{3,31,36,39},{25,27,41,43},{43},{30,40},{7,11,16,19,28,39,43,45},{8,23,41,47,49},{0,7},{9,17,25,49},{7,48},{6,15,17,48},{2,36},{2,4,5},{5,24},{8,12,30,43},{24,26,30,37},{},{5,9,23,37},{22,31,39},{},{12,19,32,41,45},{27},{20,29,40},{4,17,23,33,34,43},{},{18,21,31},{19,39,40,49},{16,22,34,36,49},{7,24,43},{27,39},{1},{5,8,33,42},{29,37},{},{1,2,34,47},{11,40},{21,30,34,35},{},{6,10,21},{3,45},{3,29},{8,17,32,41},{23},{2,29},{29},{7,9,14},{3,4,11,27,37},{0,14,28,34},{3,35,44}};
    cout<<Solution().isBipartite(graph)<<endl;
}
