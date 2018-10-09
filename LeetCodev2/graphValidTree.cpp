class Solution {
public:
    void createMap(vector<vector<bool>> &graphs, vector<pair<int,int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            pair<int,int> current = edges[i];
            
            graphs[current.first][current.second] = true;
            graphs[current.second][current.first] = true;
        }
    }
    
    bool checkCycles(vector<vector<bool>> &graphs, vector<bool>&visited, int n) {
        queue<pair<int,int>> Q;
        Q.push({0, -1});
        
        while(!Q.empty()) {
            pair<int,int> p = Q.front();
            int father = p.second;
            int current = p.first;
            visited[current] = true;
            Q.pop();
            
            for (int i = 0; i < n; i++) {
                if (graphs[current][i] && !visited[i] && i != father) {
                    Q.push({i, current});
                } else if (graphs[current][i] && visited[i] && i != father) {
                    return false;
                }
            }
        }
        
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) return false;
        }
        
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0) return false;
        if (n == 1) return true;
        
        vector<vector<bool>> graphs (n,vector<bool> (n, false));
        vector<bool> visited (n, false);
        
        createMap(graphs, edges);    
        return checkCycles(graphs, visited, n);
    }
};