#include <iostream>
#include <string>

//Nguyen Duc Truong Giang giangndtgch18231

std::string caesarDecrypt(const std::string& input){
    std::string output;
    for(char i : input){
        if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z') output += i - 3;
    }
    return output;
}

int main() {
    std::cout << caesarDecrypt("ELOO lv zdwfklqj");
}