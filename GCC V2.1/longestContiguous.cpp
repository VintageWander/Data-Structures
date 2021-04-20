#include <iostream>
#include <string>
#include <vector>

//Nguyen Duc Truong Giang giangndtgch18231

std::string longestContiguous(const std::vector<int>& input){
    int first = 0, last = 0, count = 1, max = 0;
    int finalFirst = 0, finalLast = 0;
    for(int i = 1; i <= input.size(); ++i){
        int prevNumber = input[i - 1];
        if (prevNumber >= input[i] && count >= max){
            finalFirst = first;
            finalLast = last;
            first = last = i;
            max = count;
            count = 1;
        }
        if(prevNumber < input[i]){
            last = i;
            ++count;
        }
    }
    std::string sentence = "The subarray is {";
    for(int i = finalFirst; i <= finalLast; ++i){
        sentence += std::to_string(input[i]);
        if(i < finalLast) sentence += ", ";
    }
    sentence += '}';
    std::cout << sentence;
    return sentence;
}

int main() {
    std::vector<int> input = {5,6,3,5,7,8,9,1,2};
    longestContiguous(input);
}
