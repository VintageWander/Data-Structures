#include <iostream>
#include <string>
#include <vector>

bool checkPerfect(const std::string& input){
    int ascii[26]= {0}, count = 0;
    for(int i = 0; i < input.size(); ++i) {
        if (input[i] != ' ' && !ascii[(int)input[i] - 97]){
            ascii[(int)input[i] - 97] = 1;
            ++count;
        }
    }
    return (count == 26) ? true : false;
}


int main() {
    std::string input = "the quick brown fox jumps over the lazy dog";
    if(checkPerfect(input)) std::cout << "yes";
    else std::cout << "no";
}