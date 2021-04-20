#include <iostream>
#include <string>

//Nguyen Duc Truong Giang giangndtgch18231

std::string findLongestWord(const std::string& input){
    std::string result, maxString;
    for(char i : input){
        if(i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z')
            result += i;
        if(i == ' ' || i == *(input.end() - 1)) {
            if (result.length() > maxString.length())
                result = (maxString = std::move(result), "");
            }
        }
    return maxString;
}

int main() {
    std::cout << findLongestWord("fun@!*ny time");
}