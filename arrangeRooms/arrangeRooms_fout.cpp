#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ofstream;

void backtrackRecursion(int& currA, int& currC, int (&A)[5], int (&C)[5],
                       vector<vector<int>>& result, vector<int>& temp){
    if(currA <= 0 && currC <= 0){
        result.emplace_back(temp);
        return;
    }
    for(int i = 0; i < 5; ++i){
        if(currA - A[i] >= 0 && currC - C[i] >= 0){
            currA -= A[i];
            currC -= C[i];
            temp.emplace_back(i);
            backtrackRecursion(currA, currC, A, C, result, temp);
            currA += A[i];
            currC += C[i];
            temp.pop_back();
        }
    }
}

vector<vector<int>> calculate(int& inputA, int& inputC){
    int A[5] = {2,0,2,1,1};
    int C[5] = {1,3,0,1,0};
    vector<vector<int>> result;
    vector<int> temp;
    backtrackRecursion(inputA, inputC, A, C, result, temp);
    return result;
}

int main(){
    ofstream fout; 
    fout.open("output.txt");
    int inputA = 0;
    int inputC = 0;
    fout << "Amount of adults: "; cin >> inputA;
    fout << "Amount of children: "; cin >> inputC;
    auto test = calculate(inputA, inputC);
    for(int i = 0; i < test.size(); ++i){
        fout << "\nOption " << i + 1 << '\n';
        for(int j = 0; j < test[i].size(); ++j){
            switch(test[i][j]){
                case 0: fout << "King 2A + 1C\n"; break;
                case 1: fout << "King 3C\n"; break;
                case 2: fout << "Queen 2A\n"; break;
                case 3: fout << "Queen 1A + 1C\n"; break;
                case 4: fout << "Single 1A\n"; break;
                default: fout << "Wait this is illegal\n"; break;
            }
        }
    }
    fout.close();
    return 0;
}