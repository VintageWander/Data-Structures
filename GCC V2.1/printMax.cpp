#include <iostream>
#include <queue>
#include <list>

//Nguyen Duc Truong Giang giangndtgch18231

int printMax(const int& input){
    std::priority_queue<int> storage;
    auto copy = input;
    while (copy != 0){
        storage.emplace(copy % 10);
        copy /= 10;
    }
    while (!storage.empty()){
        copy += (int)storage.top();
        storage.pop();
        copy *= 10;
    }
    return copy /= 10;
}

int main() {
    std::cout << printMax(2019);
}