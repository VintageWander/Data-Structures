#include <iostream>
#include <vector>
using std::vector;

void dfs(vector<vector<char>>& grid, int i, int j){
    if(i < 0||j < 0||i >= grid.size()||j >= grid[i].size()||grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i+1, j);
    dfs(grid, i, j+1);
    dfs(grid, i-1, j);
    dfs(grid, i, j-1);
}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            if(grid[i][j] == '1'){
                ++count;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    auto test = numIslands(grid);
    std::cout << test;
}