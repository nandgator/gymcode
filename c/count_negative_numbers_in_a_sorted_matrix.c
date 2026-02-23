/* Leetcode 1351. Count Negative Numbers in a Sorted Matrix

Given a `m x n` matrix grid which is sorted in non-increasing order both
row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:
    - m == grid.lengthh
    - n == grid[i].length
    - 1 <= m, n <= 100
    - -100 <= grid[i][j] <= 100

Follow up: Could you find an O(n + m) solution? */

// Solution by: @nandgator

/* Note to self:
Why is gridColSize a pointer?
Here the matrix is treated as an array of rows, and each row can technically
have a different number of columns. So if the matrix is:
[
  [4,3,2,-1],
  [3,2,1,-1],
  [1,1,-1,-2],
  [-1,-1,-2,-3]
]
Then:
gridSize = 4
gridColSize = {4,4,4,4}
This apporach can accomodate for jagged arrays too. */

#include <stdio.h>
#include <stdlib.h>

int countNegatives(int **grid, int gridSize, int *gridColSize) {
  int negatives = 0;

  // Linear - O(m * n)
  // for (int idx = 0; idx < gridSize; idx++) {
  //     for (int jdx = 0; jdx < gridColSize[idx]; jdx++) {
  //         if (grid[idx][jdx] >= 0){
  //             continue;
  //         }
  //         negatives += 1;
  //     }
  // }
  // return negatives;

  // Liner & Binary - O(m log n)
  // for (int idx = 0; idx < gridSize; idx++) {
  //   int left = 0;
  //   int right = gridColSize[idx] - 1;
  //   int cursor = 0;
  //   while (left <= right) {
  //     cursor = left + (right - left) / 2;
  //     if (grid[idx][cursor] < 0) {
  //       right = cursor - 1;
  //     } else {
  //       left = cursor + 1;
  //     }
  //   }
  //   negatives += gridColSize[idx] - left;
  // }
  // return negatives;

  // O(m + n)
  int colPos = gridColSize[0] - 1;
  for (int idx = 0; idx < gridSize; idx++) {
    // make sure to stay within row bounds even for jagged array
    if (colPos >= gridColSize[idx])
      colPos = gridColSize[idx] - 1;
    int jdx = colPos;
    for (; jdx >= 0; jdx--) {
      if (grid[idx][jdx] >= 0) {
        colPos = jdx + 1;
        negatives += gridColSize[idx] - colPos;
        break;
      }
    }
    // if jdx is defined above the loop, checking
    // `flag` is eqvialent to checking if jdx == -1
    if (jdx <= -1) {
      negatives += gridColSize[idx];
    }
  }
  return negatives;
}

int main() {
  int rows = 4;
  int cols = 4;
  int gridColSize[] = {cols, cols, cols, cols};
  int **grid = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    grid[i] = malloc(cols * sizeof(int));
  }
  // clang-format off
  grid[0][0] =  4; grid[0][1] =  3;  grid[0][2] =  2;  grid[0][3] = -1;
  grid[2][0] =  1; grid[2][1] =  1;  grid[2][2] = -1;  grid[2][3] = -2;
  grid[1][0] =  3; grid[1][1] =  2;  grid[1][2] =  1;  grid[1][3] = -1;
  grid[3][0] = -1; grid[3][1] = -1;  grid[3][2] = -2;  grid[3][3] = -3;
  // clang-format on
  int result = countNegatives(grid, rows, gridColSize);
  printf("Result: %d\n", result);
  for (int i = 0; i < rows; i++) {
    free(grid[i]);
  }
  free(grid);
  return 0;
}
