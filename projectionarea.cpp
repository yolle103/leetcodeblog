#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int projectionArea2(vector<vector<int>> & grid){
        int maxrow = -1;
        int maxcolomn = -1;
        int totalp = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                if(grid[i][j] > 0)
                    totalp += 1;
                maxcolomn = max(maxcolomn, grid[j][i]);
                maxrow = max(maxrow, grid[i][j]);
            }
            totalp += (maxcolomn+maxrow);

        }
        return totalp;
    }
    int projectionArea(vector<vector<int>>& grid) {
        return zproject(grid) + xproject(grid) + yproject(grid);
    }
    int zproject(vector<vector<int>> & grid){
        int sum = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size(); j++){
                if(grid[i][j] > 0)
                    sum += 1;
            }
        }
        return sum;
    }
    int xproject(vector<vector<int>> & grid){
        int sum=0;
        for(int i=0;i<grid.size();i++){
            //find the max among each colomn
            int max = -1;
            for(int j=0;j<grid.size(); j++){
                if(grid[j][i] > max)
                    max = grid[j][i];
            }
            sum += max;
        }
        return sum;
    }
    int yproject(vector<vector<int>> & grid){
        int sum=0;
        for(int i=0;i<grid.size();i++){
            //find the max among each colomn
            int max = -1;
            for(int j=0;j<grid.size(); j++){
                if(grid[i][j] > max)
                    max = grid[i][j];
            }
            sum += max;
        }
        return sum;
    }
    
};  
int main(){
    vector<vector<int>> grid =  {{1,0},{0,2}};
    cout<<Solution().projectionArea2(grid)<<endl;
}
