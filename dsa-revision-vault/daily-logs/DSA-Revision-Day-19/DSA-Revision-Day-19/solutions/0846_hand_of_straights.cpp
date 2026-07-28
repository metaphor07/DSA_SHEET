class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;

        for (int card : hand) freq[card]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int x = start; x < start + groupSize; x++) {
                if (!freq.count(x)) return false;

                freq[x]--;

                if (freq[x] == 0) freq.erase(x);
            }
        }

        return true;
    }
};
