class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dumba = res;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        while (head != nullptr) {
            head = head->next;
            dumba = dumba->next;
        }

        dumba->next = dumba->next->next;

        ListNode* result = res->next;
        delete res;
        return result;        
    }
};