#include <iostream>
#include <vector>

void printRatio(const std::vector<int>& input){
    unsigned int positive = 0, negative = 0, zeros = 0;
    for(int i = 0; i < input.size(); ++i)
    {
        if(input[i] > 0) ++positive;
        if(input[i] < 0) ++negative;
        if(input[i] == 0) ++zeros;
    } 
    std::cout << "Positive: " << (double)positive / input.size() << '\n';
    std::cout << "Negative: " << (double)negative / input.size() << '\n';
    std::cout << "Zero: " << (double)zeros / input.size() << '\n';
}

int main() {
    std::vector<int> input{1,2,0,-1,-2};
    printRatio(input);

}

