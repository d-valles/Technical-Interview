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
    bool isOdd(int x) {
        return x % 2 != 0;
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode *startOdd = new ListNode(1);
        ListNode *startEven = new ListNode(1);
        
        ListNode *currentOdd = startOdd;
        ListNode *currentEven = startEven;
        
        int count = 1;
        
        while (head) {
            if (isOdd(count)) {
                currentOdd->next = head;
                currentOdd = currentOdd->next;
            } else {
                currentEven->next = head;
                currentEven = currentEven->next;
            }
            count++;
            head = head->next;
        }
        currentEven->next = NULL;
        currentOdd->next = startEven->next;
        
        return startOdd->next;
    }
};