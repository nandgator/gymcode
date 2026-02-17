#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int pointer = (right - left) / 2;
        while (left <= right) {
            pointer = left + ((right - left) / 2);
            std::cout << "pointer: " << pointer << ", left: " << left << ", right: " << right << std::endl;
            if (nums[pointer] > target) {
                right = pointer - 1;
            }
            else if (nums[pointer] < target) {
                left = pointer + 1;
            }
            else {
                break;
            }
        }
        if (nums[pointer] == target) {
            return pointer;
        }
        if (pointer == 0 && nums[pointer] > target) {
            return pointer;
        }
        if (pointer == nums.size() - 1 && nums[pointer] < target) {
            return nums.size();
        }
        if (nums[pointer] < target && nums[pointer + 1] > target) {
            return pointer + 1;
        }
        if (nums[pointer] > target && nums[pointer - 1] < target) {
            return pointer;
        }
        return pointer;
    }
};

int main() {

    Solution obj;
    vector<int> nums = { 1,3,5,6 };
    vector<int> targets = { 2 };
    vector<int> expectedResults = { 1 };
    vector<int> results;
    results.resize(expectedResults.size());

    for (int i = 0; i < targets.size(); i++) {
        results[i] = obj.searchInsert(nums, targets[i]);
        std::cout << "target: " << targets[i]
            << ", expected: " << expectedResults[i]
            << ", received: " << results[i]
            << std::endl;
    }

    return 0;
}