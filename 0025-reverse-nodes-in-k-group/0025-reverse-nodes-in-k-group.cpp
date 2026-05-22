class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        // Check if k nodes exist
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        // Reverse k nodes
        ListNode *prev = NULL, *curr = head, *next = NULL;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};