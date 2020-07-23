#include <iostream>
#include <set>
#include <string>

void permuteFuntion(std::string& string, int&& left, std::set<std::string>& solutions)
{
    if (left == string.length())
    {
        solutions.emplace(string);
    }
    else 
    {
        for(int i = left; i < string.length(); i++)
        {
            std::swap(string[left], string[i]);
            permuteFuntion(string, left + 1, solutions);
            std::swap(string[left], string[i]);
        }
    }
}

std::set<std::string> permuteString(std::string& string) 
{
    std::set<std::string> solutions;
    permuteFuntion(string, 0, solutions);
    return solutions;
};


int main()
{
    std::string testString = "hello";
    auto test = permuteString(testString);
    for (std::set<std::string>::iterator it = test.begin(); it != test.end(); it++)
    {
        std::cout << *it <<" ";
    }
    std::cout << "\n" << "The total numbers of possible permutation from the string " << testString <<" is: " << test.size();
}