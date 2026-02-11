// LeetCode 704. Binary Search

// Given an array of integers nums which is sorted in ascending order, and an
// integer target, write a function to search target in nums. If target exists,
// then return its index. Otherwise, return -1. You must write an algorithm with
// O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

// Constraints:
//     - 1 <= nums.length <= 10^4
//     - -10^4 < nums[i], target < 10^4
//     - All the integers in nums are unique.
//     - nums is sorted in ascending order.

// Solution by: @nandgator

#include <stdio.h>

// binary search
int search(int *nums, int numsSize, int target) {
  int left = 0;
  int right = numsSize - 1;
  int cursor = left + (right - left) / 2;
  while (left <= right) {
    if (target == nums[cursor]) {
      return cursor;
    } else if (target < nums[cursor]) {
      right = cursor - 1;
    } else {
      left = cursor + 1;
    }
    cursor = left + (right - left) / 2;
  }
  return -1;
}

// linear search
// for (int idx = 0; idx <= numsSize - 1; idx += 1) {
//   if (nums[idx] == target) {
//     return idx;
//   }
// }

int main() {
  int nums[] = {1, 2, 3, 4, 5, 6};
  int numSize = sizeof(nums) / sizeof(nums[0]);
  int result = search(nums, numSize, 5);
  printf("Result %d\n", result);
  return 0;
}
