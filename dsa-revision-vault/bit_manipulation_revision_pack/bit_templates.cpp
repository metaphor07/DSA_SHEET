#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using uint64 = unsigned long long;

// ------------------------------------------------------------
// Basic bit operations
// ------------------------------------------------------------

bool isBitSet(uint64 n, int bit) {
    return (n & (1ULL << bit)) != 0;
}

uint64 setBit(uint64 n, int bit) {
    return n | (1ULL << bit);
}

uint64 clearBit(uint64 n, int bit) {
    return n & ~(1ULL << bit);
}

uint64 toggleBit(uint64 n, int bit) {
    return n ^ (1ULL << bit);
}

int countSetBits(uint64 n) {
    return __builtin_popcountll(n);
}

bool isPowerOfTwo(uint64 n) {
    return n != 0 && (n & (n - 1)) == 0;
}

uint64 removeLowestSetBit(uint64 n) {
    return n & (n - 1);
}

uint64 isolateLowestSetBit(uint64 n) {
    return n & (~n + 1);
}

// ------------------------------------------------------------
// XOR helpers
// ------------------------------------------------------------

int64 xorOneToN(int64 n) {
    if (n < 0) return 0;

    switch (n & 3LL) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}

int64 xorRange(int64 left, int64 right) {
    return xorOneToN(right) ^ xorOneToN(left - 1);
}

int singleNumber(const vector<int>& nums) {
    int answer = 0;

    for (int x : nums) {
        answer ^= x;
    }

    return answer;
}

pair<int, int> twoUniqueNumbers(const vector<int>& nums) {
    int totalXor = 0;

    for (int x : nums) {
        totalXor ^= x;
    }

    int differingBit = totalXor & -totalXor;

    int first = 0;
    int second = 0;

    for (int x : nums) {
        if (x & differingBit) {
            first ^= x;
        } else {
            second ^= x;
        }
    }

    return {first, second};
}

// ------------------------------------------------------------
// Subset and submask templates
// ------------------------------------------------------------

void enumerateAllSubsets(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    for (uint64 mask = 0; mask < (1ULL << n); mask++) {
        vector<int> subset;

        for (int bit = 0; bit < n; bit++) {
            if (mask & (1ULL << bit)) {
                subset.push_back(nums[bit]);
            }
        }

        // Process subset here.
    }
}

void enumerateSetBits(uint64 mask) {
    uint64 current = mask;

    while (current != 0) {
        int bit = __builtin_ctzll(current);
        uint64 lowbit = current & (~current + 1);

        // Process bit or lowbit here.
        (void)bit;
        (void)lowbit;

        current &= (current - 1);
    }
}

void enumerateAllSubmasks(int mask) {
    int sub = mask;

    while (true) {
        // Process sub here.

        if (sub == 0) {
            break;
        }

        sub = (sub - 1) & mask;
    }
}

// ------------------------------------------------------------
// Prefix XOR
// ------------------------------------------------------------

vector<int> buildPrefixXor(const vector<int>& nums) {
    vector<int> prefix(nums.size() + 1, 0);

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        prefix[i + 1] = prefix[i] ^ nums[i];
    }

    return prefix;
}

int rangeXor(const vector<int>& prefix, int left, int right) {
    return prefix[right + 1] ^ prefix[left];
}

long long countSubarraysWithXorK(const vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    frequency[0] = 1;

    int prefixXor = 0;
    long long answer = 0;

    for (int x : nums) {
        prefixXor ^= x;
        answer += frequency[prefixXor ^ k];
        frequency[prefixXor]++;
    }

    return answer;
}

// ------------------------------------------------------------
// Range AND
// ------------------------------------------------------------

int rangeBitwiseAnd(int left, int right) {
    while (left < right) {
        right &= (right - 1);
    }

    return right;
}

// ------------------------------------------------------------
// Addition without +
// ------------------------------------------------------------

int addWithoutPlus(int a, int b) {
    while (b != 0) {
        unsigned int carry =
            static_cast<unsigned int>(a & b) << 1;

        a ^= b;
        b = static_cast<int>(carry);
    }

    return a;
}

// ------------------------------------------------------------
// Assignment bitmask DP skeleton
// ------------------------------------------------------------

class AssignmentDP {
private:
    int n;
    vector<vector<int>> cost;
    vector<int> memo;

    int solve(int mask) {
        int person = __builtin_popcount(static_cast<unsigned int>(mask));

        if (person == n) {
            return 0;
        }

        int& answer = memo[mask];

        if (answer != -1) {
            return answer;
        }

        answer = INT_MAX / 4;

        for (int job = 0; job < n; job++) {
            if ((mask & (1 << job)) == 0) {
                answer = min(
                    answer,
                    cost[person][job] + solve(mask | (1 << job))
                );
            }
        }

        return answer;
    }

public:
    int minimumAssignmentCost(vector<vector<int>> inputCost) {
        cost = move(inputCost);
        n = static_cast<int>(cost.size());
        memo.assign(1 << n, -1);

        return solve(0);
    }
};

// ------------------------------------------------------------
// Pairing bitmask DP skeleton
// ------------------------------------------------------------

class PairingDP {
private:
    int n;
    vector<vector<int>> score;
    vector<int> memo;

    int solve(int mask) {
        if (mask == (1 << n) - 1) {
            return 0;
        }

        int& answer = memo[mask];

        if (answer != INT_MIN) {
            return answer;
        }

        int firstUnused = -1;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                firstUnused = i;
                break;
            }
        }

        answer = INT_MIN / 4;

        for (int j = firstUnused + 1; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                int newMask =
                    mask |
                    (1 << firstUnused) |
                    (1 << j);

                answer = max(
                    answer,
                    score[firstUnused][j] + solve(newMask)
                );
            }
        }

        return answer;
    }

public:
    int maximumPairingScore(vector<vector<int>> inputScore) {
        score = move(inputScore);
        n = static_cast<int>(score.size());
        memo.assign(1 << n, INT_MIN);

        return solve(0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Add test code here.

    return 0;
}
