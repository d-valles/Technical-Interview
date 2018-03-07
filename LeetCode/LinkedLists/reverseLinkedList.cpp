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
	ListNode* reverseListRecursive(ListNode* head) {
		if(!head || !head->next) {
			return head;
		}

		ListNode* temp = reverseListRecursive(head->next);
		head->next->next = head;
		head->next = null;
		return temp;
	}

    ListNode* reverseListIterative(ListNode* head) {
        if(!head) return NULL;

        ListNode* current = head;
        ListNode* temporal = NULL;
        ListNode* prev = NULL;

        while(current) {
        	head = current;
        	temporal = current->next;
        	current->next = prev;
        	prev = current;
        	current = temporal;
        }

        return head;
    }
};