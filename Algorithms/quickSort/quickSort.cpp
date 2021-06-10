#include <iostream>
#include <algorithm>
#include <vector>
using std::vector, std::swap, std::size_t;

size_t partition (vector<int>& arr, size_t low, size_t high){
	int pivot = arr[high];
	size_t i = low - 1;
	for (size_t j = low; j <= high - 1; j++) if (arr[j] <= pivot) std::swap(arr[++i], arr[j]);
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}
void quickSort(vector<int>& arr, size_t low, size_t high){
	if (low < high){
		size_t pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	vector<int> arr = {10, 7, 8, 9, 1, 5, 20};
	quickSort(arr, 0, arr.size() - 1);
	printf("Sorted array: \n");
	for(const auto& i : arr) std::cout << i << ' ';
	return 0;
}

