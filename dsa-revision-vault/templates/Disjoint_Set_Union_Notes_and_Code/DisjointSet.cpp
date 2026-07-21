#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> rankValue;
    vector<int> componentSize;
    vector<int> parent;

public:
    // Supports both 0-based nodes [0, n-1] and 1-based nodes [1, n].
    explicit DisjointSet(int n) {
        rankValue.assign(n + 1, 0);
        componentSize.assign(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Finds the representative/ultimate parent of a component.
    // Path compression makes all visited nodes point directly to the root.
    int findUltimateParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] =
            findUltimateParent(parent[node]);
    }

    // Connects two components using their tree ranks.
    void unionByRank(int u, int v) {
        int rootU = findUltimateParent(u);
        int rootV = findUltimateParent(v);

        if (rootU == rootV) {
            return;
        }

        if (rankValue[rootU] < rankValue[rootV]) {
            parent[rootU] = rootV;
        } else if (rankValue[rootU] > rankValue[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rankValue[rootU]++;
        }
    }

    // Connects the smaller component below the larger component.
    void unionBySize(int u, int v) {
        int rootU = findUltimateParent(u);
        int rootV = findUltimateParent(v);

        if (rootU == rootV) {
            return;
        }

        if (componentSize[rootU] < componentSize[rootV]) {
            parent[rootU] = rootV;
            componentSize[rootV] += componentSize[rootU];
        } else {
            parent[rootV] = rootU;
            componentSize[rootU] += componentSize[rootV];
        }
    }

    bool isConnected(int u, int v) {
        return findUltimateParent(u) ==
               findUltimateParent(v);
    }

    // Use this after performing unions through unionBySize.
    int getComponentSize(int node) {
        int root = findUltimateParent(node);
        return componentSize[root];
    }
};

int main() {
    cout << boolalpha;

    // Example 1: use only union by size.
    DisjointSet bySize(7);

    bySize.unionBySize(1, 2);
    bySize.unionBySize(2, 3);
    bySize.unionBySize(4, 5);
    bySize.unionBySize(6, 7);
    bySize.unionBySize(5, 6);

    cout << "Union by size:\n";
    cout << "1 and 3 connected: "
         << bySize.isConnected(1, 3) << '\n';
    cout << "3 and 7 connected: "
         << bySize.isConnected(3, 7) << '\n';

    bySize.unionBySize(3, 7);

    cout << "3 and 7 connected after union: "
         << bySize.isConnected(3, 7) << '\n';
    cout << "Component size containing node 7: "
         << bySize.getComponentSize(7) << "\n\n";

    // Example 2: use only union by rank.
    DisjointSet byRank(5);

    byRank.unionByRank(1, 2);
    byRank.unionByRank(2, 3);
    byRank.unionByRank(4, 5);

    cout << "Union by rank:\n";
    cout << "1 and 3 connected: "
         << byRank.isConnected(1, 3) << '\n';
    cout << "1 and 5 connected: "
         << byRank.isConnected(1, 5) << '\n';

    byRank.unionByRank(3, 5);

    cout << "1 and 5 connected after union: "
         << byRank.isConnected(1, 5) << '\n';

    return 0;
}
