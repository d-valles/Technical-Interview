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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        ListNode* headPTR = head;
        int count = 0;
        //count and connect
        while(head->next) {
            count++;
            head = head->next;
        }
        
        head->next = headPTR;
        head = headPTR;
        
        count++;
        int len = (count - (k%count)) - 1;
        
       while(len--) {
            head = head->next;           
        } 
        
        headPTR = head->next;
        head->next = NULL;
        
        return headPTR;
    }
};