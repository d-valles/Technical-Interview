/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue <int, vector<int>, greater<int> > P;
    ListNode* current = new ListNode(0);
    ListNode* start = current;
    
    for (int i = 0; i < A.size(); i++) {
        ListNode* c  = A[i];
        while (c) {
            P.push(c->val);
            c = c->next;
        }
    }
    
    while (!P.empty()) {
        start->next = new ListNode(P.top());
        start = start->next;
        P.pop();
    }
    
    return current->next;
}
