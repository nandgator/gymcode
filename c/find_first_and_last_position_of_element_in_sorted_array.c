/* LeetCode 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
    - 0 <= nums.length <= 10^5
    - -10^9 <= nums[i] <= 10^9
    - nums is a non-decreasing array.
    - -10^9 <= target <= 10^9 */

// Solution by: @nandgator

// Note to Self: `returnSize` is a pointer because:
// 1. C doesn’t support multiple return values.
// 2. So the caller passes an address.
// 3. You write into that address.
// 4. That’s how you “return” the array size.
// "Return one thing directly, pass other outputs by pointer."

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *result = malloc(*returnSize * sizeof(int));
  result[0] = -1;
  result[1] = -1;
  if (numsSize <= 0) {
    return result;
  }
  int left = 0;
  int right = numsSize - 1;
  int cursor = 0;
  // lower-bound-search
  while (left <= right) {
    cursor = left + (right - left) / 2;
    if (target <= nums[cursor]) {
      right = cursor - 1;
    } else {
      left = cursor + 1;
    }
  }
  if (left < numsSize && nums[left] == target) {
    result[0] = left;
    left = 0;
    right = numsSize - 1;
    // upper bound search
    while (left <= right) {
      cursor = left + (right - left) / 2;
      if (target < nums[cursor]) {
        right = cursor - 1;
      } else {
        left = cursor + 1;
      }
    }
    if (right < numsSize && nums[right] == target) {
      result[1] = right;
      return result;
    }
  }
  return result;
}

int main() {
  int nums[] = {1, 3, 3, 3, 6};
  int numSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;
  int *result = searchRange(nums, numSize, 3, &returnSize);
  printf("Result: ");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(result);
  return 0;
}
