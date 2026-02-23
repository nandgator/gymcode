/* LeetCode 436. Find Right Interval

You are given an array of `intervals`, where `intervals[i] = [start\_i, end\_i]`
and each `start\_i` is unique.

The right interval for an interval `i` is an interval `j` such that `start\_j >=
end\_i` and `start\_j` is minimized. Note that `i` may equal `j`.

Return an array of right interval indices for each interval `i`. If no right
interval exists for interval `i`, then put `-1` at index `i`.

Example 1:
Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start\_0 = 3 is the smallest start
that is >= end\_1 = 3. The right interval for [1,2] is [2,3] since start\_1 = 2
is the smallest start that is >= end\_2 = 2.

Example 3:
Input: intervals = [[1,4],[2,3],[3,4]]
Output: [-1,2,-1]
Explanation: There is no right interval for [1,4] and [3,4].
The right interval for [2,3] is [3,4] since start\_2 = 3 is the smallest start
that is >= end\_1 = 3.

Constraints:
    - 1 <= intervals.length <= 2 * 10^4
    - intervals[i].length == 2
    - -10^6 <= start\_i <= end\_i <= 10^6
    - The start point of each interval is unique. */

// Solution by: @nandgator

// Note to self:
//  - `start\_i` == (implies) ==> `i` is a subscript of `start`.
//  - "Right" = direction (to the right on number line)
//  - "`start\_j` is minimized" = choose the closest valid start
//  - `i` may equal `j`, but only if `start\_i` == `end\_j`

#include <stdio.h>
#include <stdlib.h>

struct Pair {
  int start;
  int index;
};

int compare(const void *a, const void *b) {
  const struct Pair *p1 = a;
  const struct Pair *p2 = b;
  return p1->start - p2->start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRightInterval(int **intervals, int intervalsSize,
                       int *intervalsColSize, int *returnSize) {
  // Early return unnecessary
  // *returnSize = 1;
  // if (intervalsSize <= 1) {
  //   int *result = malloc(*returnSize * sizeof(int));
  //   result[0] = -1;
  //   return result;
  // }
  // struct Pair arr[intervalsSize];
  // VLA (variable-length array) may cause large
  // stack allocations issues with LeetCode. Instead ...
  struct Pair *arr = malloc(intervalsSize * sizeof(struct Pair));
  for (int idx = 0; idx < intervalsSize; idx++) {
    arr[idx].start = intervals[idx][0];
    arr[idx].index = idx;
  }
  qsort(arr, intervalsSize, sizeof(struct Pair), compare);
  *returnSize = intervalsSize;
  int *result = malloc(*returnSize * sizeof(int));
  for (int idx = 0; idx < intervalsSize; idx++) {
    int left = 0;
    int right = intervalsSize - 1;
    while (left <= right) {
      int cursor = left + (right - left) / 2;
      int target = intervals[idx][1];
      if (target <= arr[cursor].start) {
        right = cursor - 1;
      } else {
        left = cursor + 1;
      }
    }
    if (left < intervalsSize) {
      result[idx] = arr[left].index;
    } else {
      result[idx] = -1;
    }
  }
  free(arr);
  return result;
}

int main() {
  int rows = 4;
  int cols = 2;
  int gridColSize[] = {cols, cols, cols, cols};
  int **intervals = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    intervals[i] = malloc(cols * sizeof(int));
  }
  // clang-format off
  intervals[0][0] = 3; intervals[0][1] = 4;
  intervals[1][0] = 2; intervals[1][1] = 3;
  intervals[2][0] = 1; intervals[2][1] = 2;
  intervals[3][0] = -1; intervals[3][1] = 0;
  // clang-format on
  int returnSize;
  int *result = findRightInterval(intervals, rows, gridColSize, &returnSize);
  printf("Result: ");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(result);
  for (int i = 0; i < rows; i++) {
    free(intervals[i]);
  }
  free(intervals);
  return 0;
}
