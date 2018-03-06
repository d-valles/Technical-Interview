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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        
        ListNode* HD = new ListNode(0);
        ListNode* current = HD;
        
        while(l1 || l2) {
            int nValue = 0;
            if (!l1) {
                nValue = l2->val;
                l2 = l2->next;
            }
            else if (!l2 || l1->val <= l2->val) {
                nValue = l1->val;
                l1 = l1->next;
            } else {
                nValue = l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode(nValue);
            current = current->next;
        }
        return HD->next;
    }
};