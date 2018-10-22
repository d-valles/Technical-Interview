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
    
    //NuLL 1 2 3 4 5
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while(current) {
            ListNode* next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        
        return prev;
    }
};