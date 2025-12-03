class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next; // store next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev
            curr = nextNode;                 // move forward
        }
        return prev; // new head
    }
};
