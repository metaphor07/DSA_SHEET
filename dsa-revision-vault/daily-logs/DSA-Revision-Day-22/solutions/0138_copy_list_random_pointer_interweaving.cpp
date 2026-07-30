class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* curr = head;

        while (curr) {
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next;
        }

        curr = head;

        while (curr) {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;

        while (curr) {
            Node* copyNode = curr->next;
            curr->next = copyNode->next;
            copyNode->next = copyNode->next ? copyNode->next->next : NULL;
            curr = curr->next;
        }

        return copyHead;
    }
};
