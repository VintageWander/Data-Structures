#include <iostream>
#include <vector>
using std::vector;

void solve(int i, int j, int& n, int& m, 
           vector<vector<int>>& board, vector<vector<int>>& path, vector<vector<int>>& result)
{
    if(i >= n || j >= m || i < 0 || j < 0) return;
    if(path[i][j] || board[i][j]) return;
    if(i == n - 1 && j == m - 1){
        path[i][j] = 1;
        result = path;
        return;
    }
    if(result[n - 1][m - 1]) return;
    else {
        path[i][j] = 1;
        solve(i, j + 1, n, m, board, path, result);
        solve(i + 1, j, n, m, board, path, result);
        solve(i, j - 1, n, m, board, path, result);
        solve(i - 1, j, n, m, board, path, result);
        path[i][j] = 0;
    }
}

int main(){
    vector<vector<int>> board = {
                                 {0,1,0,0,0},
                                 {0,1,0,1,0},
                                 {0,0,0,1,0},
                                 {1,1,1,0,0},
                                 {0,0,0,0,1},
                                 {0,1,1,1,0},
                                 {0,0,0,0,0}
                                };
    vector<vector<int>> path  (board.size(), vector<int>(board[0].size(), 0));
    vector<vector<int>> result(board.size(), vector<int>(board[0].size(), 0));
    int n = board.size();
    int m = board[0].size();
    solve(0, 0, n, m, board, path, result);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[0].size(); ++j){
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << ' ';
}