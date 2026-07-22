class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pb] < rank[pa]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (!emailToAccount.count(email)) {
                    emailToAccount[email] = i;
                } else {
                    unite(i, emailToAccount[email]);
                }
            }
        }

        unordered_map<int, vector<string>> groups;

        for (auto& it : emailToAccount) {
            string email = it.first;
            int acc = it.second;
            int parentAcc = find(acc);
            groups[parentAcc].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto& it : groups) {
            int acc = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> merged;
            merged.push_back(accounts[acc][0]);

            for (string& email : emails) merged.push_back(email);

            ans.push_back(merged);
        }

        return ans;
    }
};
