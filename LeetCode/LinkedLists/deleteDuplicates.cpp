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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while(current) {
            if(!prev || prev->val != current->val) {
                prev = current;
                current = current->next;
            } else {
                prev->next = current->next;
                current = prev->next;
            }
        }
        
        return head;        
    }
};
