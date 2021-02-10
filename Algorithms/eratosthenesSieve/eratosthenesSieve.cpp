#include <iostream>
#include <algorithm>
#include <cmath>
/*
 * How to use:
 *
 * Input:
 * First input the how many times the algorithm should run
 * Based on the amount of time you input, input in the start and end numbers
 *
 * Output:
 * Number of primes within the range
 *
 * For example:
 *
 * Input:
 * 3
 * 2 20    range from 2 to 20
 * 20 100  range from 20 to 100
 * 1 100   range from 1 100
 *
 * Output:
 * 8       2 -> 20 has 8 primes
 * 17      20 -> 100 has 17 primes
 * 25      1 -> 100 has 25 primes
 * 
 * */

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
    //length = max + 1 because then the final index will be the exact number
    unsigned int length = max + 1;
    //create the array to sieve
    bool array[length];
    //each elements are true
    for(int i = 0; i != length; ++i) array[i] = true;
    //make these two false so the print area won't call out 0 and 1 as primes
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
    //print
    unsigned int count = 0;
    for(int i = 0; i != cases; ++i){
        for(unsigned int j = start[i]; j != end[i]; ++j) {
            if(array[j]) ++count;
        }
        std::cout << count << '\n'; count = 0;
    }
}
