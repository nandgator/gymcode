// LeetCode 744. Find Smallest Letter Greater Than Target

// You are given an array of characters letters that is sorted in
// non-decreasing order, and a character target. There are at least two
// different characters in letters.

// Return the smallest character in letters that is lexicographically
// greater than target. If such a character does not exist, return the first
// character in letters.

// Example 1:
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater
// than 'a' in letters is 'c'.

// Example 2:
// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater
// than 'c' in letters is 'f'.

// Example 3:
// Input: letters = ["a","x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically
// greater than 'z' so we return letters[0].

// Constraints:
//     - 2 <= letters.length <= 10^4
//     - letters[i] is a lowercase English letter.
//     - letters is sorted in non-decreasing order.
//     - letters contains at least two different characters.
//     - target is a lowercase English letter.

// Solution by: @nandgator

// Note to self: Since the array is sorted, I binary search for the first
// element strictly greater than target. If none exists, I return the first
// element to handle wrap-around.

#include <stdio.h>
#include <string.h>

char nextGreatestLetter(char *letters, int lettersSize, char target) {
  int left = 0;
  int right = lettersSize - 1;
  int cursor = 0;
  while (left < right) {
    cursor = left + (right - left) / 2;
    if (target < letters[cursor]) {
      right = cursor;
    } else {
      left = cursor + 1;
    }
  }
  return target < letters[left] ? letters[left] : letters[0];
}

int main() {
  char letters[] = "uvwx";
  char target = 'x';
  // (sizeof(letters) - 1) / sizeof(letters[0]) == stlenlen(letters)
  // only if letters[] is computed at comptime.
  char result = nextGreatestLetter(letters, strlen(letters), target);
  printf("Result: %c\n", result);
  return 0;
}
