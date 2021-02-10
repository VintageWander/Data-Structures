#include <iostream>

int main()
{
    int numbers = 0;
    std::cin >> numbers;
    int arr[numbers] = {0};
    for(int i = 0; i < numbers; ++i){
        std::cin >> arr[i];
    }
    // main part
    int max = arr[0], curSum = 0, start = 0, end = 0, startFinal = 0, endFinal = 0;
    for (int i = 0; i < numbers ; ++i){
        if (curSum < 0) {
            curSum = 0; 
            start = i; 
            end = i;
        }
        curSum += arr[i]; ++end;
        if(max < curSum) { 
            max = curSum; 
            startFinal = start;
            endFinal = i;
        }
        else {
            max = max;
        }
    }
    std::cout << startFinal + 1 << ' ' << endFinal + 1 << '\n';
    std::cout << max;
}

