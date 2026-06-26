class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);

        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int targetIndex) {
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);

            if (pivotIndex == targetIndex) return nums[pivotIndex];
            else if (pivotIndex < targetIndex) left = pivotIndex + 1;
            else right = pivotIndex - 1;
        }

        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int targetIndex = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, targetIndex);
    }
};
