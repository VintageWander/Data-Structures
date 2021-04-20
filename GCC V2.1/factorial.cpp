#include <iostream>
#include <string>

//Nguyen Duc Truong Giang giangndtgch18231

std::string factorial(int n){
	int storage[200] = {1}, size = 1; std::string result;
	for (int i = 2; i <= n; i++) {
        int temp = 0;
        for (int j = 0; j < size; j++) {
            int product = storage[j] * i + temp;
            storage[j] = product % 10;
            temp = product / 10;
        }
        while (temp != 0){
            storage[size++] = temp % 10;
            temp /= 10;
        }
    }
	for(int i = size - 1; i >= 0; i--) result += std::to_string(storage[i]);
    return result;
}

int main() {
    std::cout << factorial(100);
}