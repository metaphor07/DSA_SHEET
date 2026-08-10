// Q4 brute force for understanding only.
// Generate every simple path and check whether labels form a palindrome.

class SolutionBrute {
public:
    int ans = 1;
    vector<vector<int>> graph;
    string label;

    bool isPalindrome(vector<int>& path) {
        int l = 0;
        int r = path.size() - 1;

        while (l < r) {
            if (label[path[l]] != label[path[r]]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    void dfs(int node, vector<int>& path, vector<int>& visited) {
        if (isPalindrome(path)) {
            ans = max(ans, (int)path.size());
        }

        for (int nei : graph[node]) {
            if (!visited[nei]) {
                visited[nei] = 1;
                path.push_back(nei);

                dfs(nei, path, visited);

                path.pop_back();
                visited[nei] = 0;
            }
        }
    }
};
