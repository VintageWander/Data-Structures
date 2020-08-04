#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <string_view>

std::vector<std::vector<std::pair<int, int>>> searchWords(std::vector<std::string>& board, std::vector<std::string>& wordList)
{
    std::vector<std::vector<std::pair<int, int>>> path;
    for (int w = 0; w < wordList.size(); w++) // iterating through the list of words
    {
        for (int i = 0; i < board.size(); i++) // iterating through rows
        {
            if (i == board.size()) break;
            for (int j = 0; j < board[i].size(); j++) // iterating through columns
            {
                if (j == board[i].size() || i == board.size()) break;
                if (wordList[w][0] == board[i][j]) // check if the first character of the word matches the current word on the board
                {
                    std::vector<std::pair<int, int>> position;
                    position.emplace_back(std::make_pair(i, j));
                    if (i >= 0 && j + 1 <= board[i].size() - 1 && board[i][j + 1] == wordList[w][1])
                    {
                        for (int m = 2; m < wordList[w].size(); m++)
                        {
                            if (j + m < board[i].size() && board[i][j + m] != wordList[w][m])
                            {
                                position.clear();
                                break;
                            }
                            if (m == (wordList[w].size() - 1))
                            {
                                position.emplace_back(std::make_pair(i, j + m));
                                path.emplace_back(position);
                                position.clear();
                                j = board[i].size() + 1; 
                                i = board.size() + 1;
                                break;
                            }
                        }
                    }
                    else if (i + 1 <= board.size() - 1 && j + 1 <= board[i].size() - 1 && board[i + 1][j + 1] == wordList[w][1])
                    {
                        for (int m = 2; m < wordList[w].size(); m++)
                        {
                            if (i + m < board.size() && j + m <= board.size() && board[i + m][j + m] != wordList[w][m])
                            {
                                position.clear();
                                break;
                            }
                            if (m == (wordList[w].size() - 1))
                            {
                                position.emplace_back(std::make_pair(i + m, j + m));
                                path.emplace_back(position);
                                position.clear();
                                j = board[i].size() + 1;
                                i = board.size() + 1; 
                                break;
                            }
                        }
                    }
                    else if (i + 1 <= board.size() - 1 && j >= 0 && board[i + 1][j] == wordList[w][1])
                    {
                        for (int m = 2; m < wordList[w].size(); m++)
                        {
                            if (i + m < board.size() && board[i + m][j] != wordList[w][m])
                            {
                                position.clear();
                                break;
                            }
                            if (m == (wordList[w].size() - 1))
                            {
                                position.emplace_back(std::make_pair(i + m, j));
                                path.emplace_back(position);
                                position.clear();
                                j = board[i].size() + 1;
                                i = board.size() + 1;
                                break;
                            }
                        }
                    }
                    else if (i + 1 <= board.size() - 1 && j - 1 >= 0 && board[i + 1][j - 1] == wordList[w][1])
                    {
                        for (int m = 2; m < wordList[w].size(); m++)
                        {
                            if (i + m < board.size() && board[i + m][j - m] != wordList[w][m])
                            {
                                position.clear();
                                break;
                            }
                            if (m == (wordList[w].size() - 1))
                            {
                                position.emplace_back(std::make_pair(i + m, j - m));
                                path.emplace_back(position);
                                position.clear();
                                j = board[i].size() + 1; 
                                i = board.size() + 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return path;
}

int main() 
{
    std::vector<std::string> board {"fccrestpuewliqc",
                                         "lelsttfrusacnus",
                                         "alkalinelpnatir",
                                         "setsnrcmstdperp",
                                         "hbohggreraehrko",
                                         "brnrnhrdanrands",
                                         "aatsiceieoirmlt",
                                         "ctoumaltgnnaeou",
                                         "korblepalngonpl",
                                         "ertnatatyashtsa",
                                         "ryeacopeacrqbut",
                                         "lbakerodrainage"};
    std::vector<std::string> wordList {"premeditated", "celebratory", "wanderings", "internment",
                                            "postulate", "flashback", "pharaoh", "alkaline",
                                            "calming","cannon", "hearer","clang", "teach",
                                            "baker", "lapse", "lapel", "quirk", "onto", "cope",
                                            "sash", "surf", "clay", "ago", "urn", "stir", "but",
                                            "bus", "lop", "rye"};


    auto test = searchWords(board, wordList);
    std::cout << " ";
    return 0;
}