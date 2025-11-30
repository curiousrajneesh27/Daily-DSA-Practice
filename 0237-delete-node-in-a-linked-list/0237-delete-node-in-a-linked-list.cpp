class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;      // step 1: copy value
        node->next = node->next->next;    // step 2: skip next node
    }
};
