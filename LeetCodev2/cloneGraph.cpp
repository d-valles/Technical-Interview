/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    UndirectedGraphNode* start = node;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> H;
    
    queue<UndirectedGraphNode*> Q;
    Q.push(node);
    
    UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
    H.emplace(node, cloneNode);
    
    while(!Q.empty()) {
        
        UndirectedGraphNode* current = Q.front();
        Q.pop();
        
        for (int i = 0; i < current->neighbors.size(); i++) {
            UndirectedGraphNode* neighbor = current->neighbors[i];
            
            if (H.find(neighbor) == H.end()) {
                UndirectedGraphNode* clone = new UndirectedGraphNode(neighbor->label);
                H.emplace(neighbor, clone);
                H[current]->neighbors.push_back(clone);
                Q.push(neighbor);
            } else {
                H[current]->neighbors.push_back(H[neighbor]);
            }
        }
    }

    return H[start];
}
