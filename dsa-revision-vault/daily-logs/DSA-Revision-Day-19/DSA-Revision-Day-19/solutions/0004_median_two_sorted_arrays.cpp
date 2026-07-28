class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        int n = A.size();
        int m = B.size();

        int total = n + m;
        int leftHalf = (total + 1) / 2;

        int low = 0;
        int high = n;

        while (low <= high) {
            int cutA = low + (high - low) / 2;
            int cutB = leftHalf - cutA;

            int leftA = (cutA == 0) ? INT_MIN : A[cutA - 1];
            int rightA = (cutA == n) ? INT_MAX : A[cutA];

            int leftB = (cutB == 0) ? INT_MIN : B[cutB - 1];
            int rightB = (cutB == m) ? INT_MAX : B[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 1) return max(leftA, leftB);
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB) high = cutA - 1;
            else low = cutA + 1;
        }

        return 0.0;
    }
};
