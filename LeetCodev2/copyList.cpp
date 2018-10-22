/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if (!A) return NULL;
    
    RandomListNode* cloned = new RandomListNode(0);
    RandomListNode* startOfCloned = cloned;
    
    unordered_map<RandomListNode*, RandomListNode*> H;
    
    while(A) {
        
      if (H.find(A) != H.end()) {
        cloned->next = H[A];
      } else  {
        cloned->next = new RandomListNode(A->label);
        H.emplace(A, cloned->next);
      }
        
        cloned = cloned->next;
      
      if (H.find(A->random) != H.end()) {
        cloned->random = H[A->random];
      } else if (A->random) {
        cloned->random = new RandomListNode(A->random->label);
        H.emplace(A->random, cloned->random);
      }
      
     A = A->next;
      
    }    
    
    return startOfCloned->next;
}
