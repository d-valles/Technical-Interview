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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        ListNode* prev = NULL;
        
        while (current) {
            if (current->val == val && !prev) {
                head = head->next;
            } else if (current->val == val) {
                prev->next = current->next;              
            } else {
                prev = current;
            }
            current = current->next;
        }
        
        return head;
    }
};