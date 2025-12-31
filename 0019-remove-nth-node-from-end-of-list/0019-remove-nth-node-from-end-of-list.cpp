class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If removing the head node
        if (fast == NULL) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        // Move both pointers
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};