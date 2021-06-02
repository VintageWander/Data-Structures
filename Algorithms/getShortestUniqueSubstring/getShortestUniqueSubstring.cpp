#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::vector;
using std::string;

string getShortestUniqueSubstring(vector<char>& arr, const string& str){
	int count = 0;
	int countArr[26] = {0};
	for(char i : arr) countArr[i - 'a'] += 1;
	for(int i = 0, j = 0; j < str.length(); ++j) {
		if(countArr[str[j] - 'a']) countArr[str[j] - 'a'] += 1;
		count += 1;
		if(count == arr.size() && countArr[str[j] - 'a'] == 2) return str.substr(i, arr.size());
		while(countArr[str[j] - 'a'] > 2){
			countArr[str[i] - 'a'] -= 1;
			count -= 1;
			++i;
		}
	}
	return "";
}
int main() {
	vector<char> arr = {'x','y','z'};
	string str = "xyyzyzyx";
	std::cout << getShortestUniqueSubstring(arr,str);
}


