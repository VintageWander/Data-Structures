#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

//return the maximum number survivor that are in order after the destruction of Thanos

int thanosSort(std::vector<int>& vector)
{
    unsigned int maxlength = 0, n = vector.size(), count = 0, storage = 0;
    for (int i = 0; i < n; i++)
    {
        if (vector[i] >= storage) { storage = vector[i]; ++count; }
    }
    if (count == n) return count;
    if (count == 0) return 1;
    while (count < n)
    {
        if (n > 1) n /= 2;
        else break;
    }
    return ceil(n);
}

int main() 
{
    std::vector<int> vector {7, 6, 5, 4, 3};
    std::cout << thanosSort(vector) << "\n";
    return 0;
}