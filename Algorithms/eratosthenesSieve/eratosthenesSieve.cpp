#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    // taking test cases
    unsigned int cases = 0;
    std::cin >> cases;
    unsigned int start[cases];
    unsigned int end[cases];
    for (int i = 0; i != cases; ++i){
        std::cin >> start[i];
        std::cin >> end[i];
    }
    // end of taking test cases

    //find max
    unsigned int max = *std::max_element(end, end + cases - 1);
    unsigned int length = max + 1;
    bool array[length];
    //make an array of size max + 1 and each element holds its own value
    for(int i = 0; i != length; ++i) array[i] = true;
    array[0] = false;
    array[1] = false;
    //square root of max stored for further use
    const int sqrtMax = std::sqrt(length);
    //algorithm
    for(int i = 2; i != sqrtMax; ++i){
        if(!array[i]) continue;
        for(int j = i * i; j < length; j += i){
            if(array[j]) array[j] = false;
        }
    }

    unsigned int count = 0;
    for(int i = 0; i != cases; ++i){
        for(unsigned int j = start[i]; j != end[i]; ++j) {
            if(array[j]) ++count;
        }
        std::cout << count << '\n'; count = 0;
    }
}
