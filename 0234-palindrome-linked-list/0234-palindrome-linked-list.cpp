class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = reverseLinkedList(slow->next);

        ListNode* first = head;
        ListNode* second = secondHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(secondHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseLinkedList(secondHead);
        return true;
    }
};
