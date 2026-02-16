// LeetCode 35. Search Insert Position

// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:
//    - 1 <= nums.length <= 10^4
//    - -10^4 <= nums[i] <= 10^4
//    - nums contains distinct values sorted in ascending order.
//    - -10^4 <= target <= 10^4

// Solution by: @nandgator

package main

func searchInsert(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	for left <= right {
		cursor := left + (right-left)/2
		if target == nums[cursor] {
			return cursor
		} else if target < nums[cursor] {
			right = cursor - 1
		} else {
			left = cursor + 1
		}
	}
	return left
}

// func main() {
// 	nums := []int{1, 3, 4, 5, 6}
// 	println("Result", searchInsert(nums, 2))
// }
