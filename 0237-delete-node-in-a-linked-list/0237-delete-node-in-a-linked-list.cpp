/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* prev = NULL;
      ListNode* curr = prev->next;
      ListNode* forward = curr->next;
      while( prev = NULL || curr = prev->next){
        prev = NULL;
        curr= prev->next;
        
      }
    }
};