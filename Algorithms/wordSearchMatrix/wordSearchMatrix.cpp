#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, word, 0, i, j)) return true;
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 
         || i >= board.size() 
         || j < 0 
         || j >= board[0].size() 
         || word[k] != board[i][j]) return false;

        if (k == word.length() - 1) return true; 

        char cur = board[i][j];
        board[i][j] = '*'; 
        bool search_next = dfs(board, word, k+1, i-1 ,j) 
                        || dfs(board, word, k+1, i+1, j) 
                        || dfs(board, word, k+1, i, j-1)
                        || dfs(board, word, k+1, i, j+1);
        board[i][j] = cur; 
        return search_next;
    }
};