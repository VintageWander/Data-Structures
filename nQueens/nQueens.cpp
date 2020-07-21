#include <iostream>
#include <vector>
#include <string>

bool isValid(int row, int col, int size, std::vector<std::vector<std::string>> &board)
{
    for (int a = 1; row - a >= 0; a++) 
    {
        if (board[row - a][col] == "Q"){ return false; }
    }
    for (int a = 1, b = 1; row - a >= 0 && col - b >= 0; a++ && b++) 
    {
        if (board[row - a][col - b] == "Q") { return false;}
    }
    for (int a = 1, b = 1; row - a >= 0 && col + b < size; a++ && b++) 
    {
        if (board[row - a][col + b] == "Q"){ return false; }
    }
    return true;
};

void Solve(int row, int col, int size, std::vector<std::vector<std::string>> &board, std::vector<std::vector<std::vector<std::string>>> &solutions)
{
    if (row == size)
    {
        if (board[row - 1][col] == "Q")
        {
            solutions.emplace_back(board);
        }
    }
    for (int i = 0; i < size; ++i)
    {
        if (isValid(row, i, size, board))
        {
            board[row][i] = "Q";
            Solve(row + 1, i, size, board, solutions);
            board[row][i] = ".";
        }
    }
};

std::vector<std::vector<std::vector<std::string>>> SolveNQueens(int n)
{
    std::vector<std::vector<std::vector<std::string>>> solutions;
    std::vector<std::vector<std::string>> board;
    for (int i = 0; i < n; i++)
    {
        std::vector<std::string> lines;
        for (int j = 0; j < n; j++)
        {
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
    int n = 4;
    auto test = SolveNQueens(n);
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int m = 0; m < 4; m++)
            {
                std::cout << test[i][j][m] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};