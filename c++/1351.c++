#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int negativeCount = 0;
        int pointer = grid[0].size() - 1;
        for (int i = 0; i < grid.size(); i++) {
            bool isPositiveFound = false;
            while (!isPositiveFound) {
                if (grid[i][pointer] >= 0 || pointer < 0) {
                    negativeCount += grid[i].size() - pointer - 1;
                    isPositiveFound = true;
                }
                else {
                    pointer--;
                }
            }

        }
        return negativeCount;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = { {4,3,2,-1}, {3,2,1,-1}, {2,1,-1,-1}, {-1,-1,-2,-3} };
    int result = obj.countNegatives(grid);
    std::cout << result;
    return 0;
}