class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sizeK;

    KthLargest(int k, vector<int>& nums) {
        sizeK = k;

        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > sizeK) {
            pq.pop();
        }

        return pq.top();
    }
};
