class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }

    void insertAfterHead(Node* node) {
        Node* oldFirst = head->next;

        head->next = node;
        node->prev = head;

        node->next = oldFirst;
        oldFirst->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key] = newNode;
    }
};
