#include <iostream>
#include <string>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    int right = 0, left = 0, count = 0, max = 0, ascii[256] = {0};
    while (right < s.length()){
        if(!ascii[s[right]]) {ascii[s[right++]] = 1; max = max > ++count ? max : count;}
        else {--count; ascii[s[left++]] = 0;}
    }
    return max;
}
int main()
{
    auto string = " ";
    int test = lengthOfLongestSubstring(string);
    std::cout << test;
    return 0;
}