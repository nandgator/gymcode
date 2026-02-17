#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int lastGreaterValue = letters[0];
        int pointer = right - ((right - left) / 2);
        while (left <= right) {
            pointer = left + ((right - left) / 2);
            if (letters[pointer] <= target) {
                left = pointer + 1;
            }
            else if (letters[pointer] > target) {
                lastGreaterValue = letters[pointer];
                right = pointer - 1;
            }
        }
        return lastGreaterValue;
    }
};

int main() {
    vector<char> letters = {'a','b','c','f'};
    Solution s;
    char result = s.nextGreatestLetter(letters, 'd');
    printf("%c\n", result);
    return 0;
}
