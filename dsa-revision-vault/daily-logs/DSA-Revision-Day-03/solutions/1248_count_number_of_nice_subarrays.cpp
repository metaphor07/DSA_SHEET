class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        int currOddCount = 0;
        int subArrCount = 0;

        for (int x : nums) {
            if (x % 2 != 0) {
                currOddCount++;
            }

            int target = currOddCount - k;

            if (prefixMap.count(target)) {
                subArrCount += prefixMap[target];
            }

            prefixMap[currOddCount]++;
        }

        return subArrCount;
    }
};
