#include <iostream>
#include <vector>
#include <string>
using std::vector, std::string;

bool isValid(int row, int col, int size, vector<vector<string>> &board)
{
    for (int a = 1; row - a >= 0; a++) {
        if (board[row - a][col] == "Q"){ return false; }
    }
    for (int a = 1, b = 1; row - a >= 0 && col - b >= 0; a++ && b++) {
        if (board[row - a][col - b] == "Q") { return false;}
    }
    for (int a = 1, b = 1; row - a >= 0 && col + b < size; a++ && b++) {
        if (board[row - a][col + b] == "Q"){ return false; }
    }
    return true;
};

void Solve(int row, int col, int size, vector<vector<string>> &board, vector<vector<vector<string>>> &solutions){
    if (row == size){
        if (board[row - 1][col] == "Q"){
            solutions.emplace_back(board);
        }
    }
    for (int i = 0; i < size; ++i){
        if (isValid(row, i, size, board)){
            board[row][i] = "Q";
            Solve(row + 1, i, size, board, solutions);
            board[row][i] = ".";
        }
    }
};

vector<vector<vector<string>>> SolveNQueens(int n){
    vector<vector<vector<string>>> solutions;
    vector<vector<string>> board;
    for (int i = 0; i < n; i++){
        vector<string> lines;
        for (int j = 0; j < n; j++){
            lines.emplace_back(".");
        }
        board.emplace_back(lines);
    }
    int r = 0, c = 0;
    Solve(r, c, n, board, solutions);
    return solutions;
};

int main() 
{
    int n = 8;
    auto test = SolveNQueens(n);
    for (int i = 0; i < test.size(); i++){
        for (int g = 0; g < n*2 + 2; g++){
            std::cout << "_";
        }
        std::cout << "\n";
        for (int j = 0; j < n; j++){
            std::cout << "|";
            for (int m = 0; m < n; m++){
                std::cout << test[i][j][m] << " ";
            }
            std::cout << "|";
            std::cout << "\n";
        }
        for (int g = 0; g < n*2 + 2; g++){
            std::cout << "-";
        }
        std::cout << "\n";
    }
};