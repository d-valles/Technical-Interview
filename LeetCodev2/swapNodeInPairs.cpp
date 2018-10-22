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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* start = newHead;
        newHead->next = head;
        
        while (head && head->next) {
            ListNode* t = head->next->next;
            
            newHead->next = head->next;
            
            head->next->next = head;
            
            head->next = t;
            
            newHead = newHead->next->next;
            head = t;
        }
        
        return start->next;
    }
};
