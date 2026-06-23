// Q1. Find the Sum of Encrypted Integers
// Time: O(total digits), Space: O(1)

class Solution {
public:
    int helper(int num) {
        if (num == 0) return 0;

        int len = 0;
        int maxDigit = 0;
        int temp = num;

        while (temp > 0) {
            maxDigit = max(maxDigit, temp % 10);
            len++;
            temp /= 10;
        }

        int encrypted = 0;
        while (len > 0) {
            encrypted = encrypted * 10 + maxDigit;
            len--;
        }

        return encrypted;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) ans += helper(num);
        return ans;
    }
};
