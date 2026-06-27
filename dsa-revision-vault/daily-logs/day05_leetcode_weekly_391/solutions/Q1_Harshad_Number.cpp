// Q1. Harshad Number
// Topic: Digit sum
// Time: O(number of digits)
// Space: O(1)

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int digitSum = 0;

        while (temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }

        if (x % digitSum == 0) {
            return digitSum;
        }

        return -1;
    }
};
