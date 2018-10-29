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

    struct cmp {
        bool operator ()(const ListNode* A,const ListNode* B) const
        {
            return A->val >= B->val;
        }
    };
    
    void getFirstOfAllLists(vector<ListNode*>& lists, priority_queue<ListNode*, vector<ListNode*>, cmp>& candidateList) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) candidateList.push(lists[i]);
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> candidateList;
        ListNode* list = new ListNode(0);
        ListNode* startOfNewList = list;
        if (!lists.size()) return NULL;
        
        getFirstOfAllLists(lists, candidateList);
        
        while(!candidateList.empty()) {
            ListNode* current = candidateList.top();
            candidateList.pop();
            
            list->next = current;
            list = list->next;
            
            if(current->next) {
                candidateList.push(current->next);   
            }
        }
        
        return startOfNewList->next;
    }
};