/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        for (int i = 0; i < n; i++) {
            curr = curr->next;
        }
        if (!curr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* need = head;
        while (curr->next) {
            need = need->next;
            curr = curr->next;
        }
        ListNode* temp = need->next;
        need->next = need->next->next;
        delete temp;
        return head;
    }
};