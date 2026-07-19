// Q2. Even Number of Knight Moves
// Topic: Chessboard color parity
// Time: O(1)
// Space: O(1)

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int startColor = (start[0] + start[1]) % 2;
        int targetColor = (target[0] + target[1]) % 2;

        return startColor == targetColor;
    }
};
