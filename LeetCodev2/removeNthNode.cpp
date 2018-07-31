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
    int getNumberOfNodes(ListNode* head) {
        if (!head) return 0;
        
        int length = 0;
        
        while (head) {
            head = head->next;
            length++;
        }
        
        return length;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        ListNode* prev = NULL;
        int lengthOfList = getNumberOfNodes(head);
        
        for (int i = 0; i < lengthOfList - n; i++) {
            prev = current;
            current = current->next;
        }
        
        if (!prev) {
            head = head->next;
            return head;
        }
        
        prev->next = current->next;
        return head;
    }
};