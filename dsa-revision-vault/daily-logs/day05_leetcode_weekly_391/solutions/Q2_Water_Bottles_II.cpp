// Q2. Water Bottles II
// Topic: Simulation / greedy
// Time: O(sqrt(numBottles)) approximately
// Space: O(1)

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            empty -= numExchange;
            ans++;
            empty++;
            numExchange++;
        }

        return ans;
    }
};
