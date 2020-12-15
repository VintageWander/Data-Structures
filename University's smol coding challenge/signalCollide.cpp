#include <iostream>
#include <algorithm>

void signalCollide(int& s1, int& s2, int& t1, int& t2){
    unsigned int arrS[100] = {0};
    unsigned int arrT[100] = {0};
    arrS[s1] = 1;
    arrT[t1] = 1;
    for(unsigned int i = s1; i < 100; i += s2){
        arrS[i] = 1;
    }
    for(unsigned int i = t1; i < 100; i += t2){
        arrT[i] = 1;
    }
    for(unsigned int i = (s1 + 1 < t1) ? t1 : s1 + 1; i < 100; ++i){
        if(arrS[i] == 1 && arrT[i] == 1) {std::cout << i; return;}
    }
}

int main() {
    int s1 = 5, s2 = 2, t1 = 0, t2 = 5;
    signalCollide(s1, s2, t1, t2);
}