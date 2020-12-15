#include <iostream>
#include <vector>
#include <string>

void wordFrame(const std::vector<std::string>& input){
    size_t max = 0;
    for(int i = 0; i < input.size(); ++i){
        max = (max < input[i].size()) ? input[i].size() : max;
    }
    for(int i = 0 ; i < max + 4; ++i){
        std::cout << '*';
    }
    std::cout << '\n';
    for(int i = 0; i < input.size(); ++i){
        std::cout << "* ";
        std::cout << input[i];
        for(int j = input[i].size(); j < max; ++j) std::cout << ' ';
        std::cout << " *";
        std::cout << '\n';
    }
    for(int i = 0 ; i < max + 4; ++i){
        std::cout << '*';
    }
}

int main() {
    std::vector<std::string> input {"Hellooooo", "World", "in", "a", "frame"};
    wordFrame(input);
}