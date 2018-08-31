class Solution {
public:
    bool isValid(pair<int,int> position, vector<vector<int>>&maze) {
        int x = maze.size();
        int y = maze[0].size();

        if (position.first < 0 || position.first >= x) return false;
        if (position.second < 0 || position.second >= y) return false;
        if (maze[position.first][position.second] == 1) return false;
        return true;
    }

    bool isVisited(pair<int,int> position, vector<vector<bool>>& visited) {
        return visited[position.first][position.second];
    }

    bool isTarget(pair<int,int> position, pair<int,int> destination) {
        return (position.first == destination.first && position.second == destination.second);
    }

    void markAsVisited(vector<vector<bool>>&visited, pair<int,int> position) {
        visited[position.first][position.second] = true;
    }
    
    bool search(vector<vector<int>>& maze, pair<int,int> position, pair<int,int> destination, vector<vector<bool>>& visited) {
        if (!isValid(position, maze)) return false;
        if (isVisited(position, visited)) return false;
        if (isTarget(position, destination)) return true;
        markAsVisited(visited, position);

        pair<int,int> rollRight = roll(1, position, maze);
        pair<int,int> rollLeft = roll(2, position, maze);
        pair<int,int> rollTop = roll(3, position, maze);
        pair<int,int> rollDown = roll(4, position, maze);

        return search(maze, rollRight, destination, visited) ||
            search(maze, rollLeft, destination, visited) ||
            search(maze, rollTop, destination, visited) ||
            search(maze, rollDown, destination, visited);
    }
    
    pair<int, int> roll(int direction, pair<int,int> position, vector<vector<int>>& maze) {
        if (direction == 1) {
            while(isValid(position, maze)) {
                position.second++;
            }
            position.second--;
        }
        if (direction == 2) {
            while(isValid(position, maze)) {
                position.second--;
            }    
            position.second++;
        }
        if (direction == 3) {
             while(isValid(position, maze)) {
                position.first++;
            }  
            position.first--;
        }
        if (direction == 4) {
             while(isValid(position, maze)) {
                position.first--;
            } 
            position.first++;
        }
        return position;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(!maze.size()) return false;

        vector<bool> rv(maze[0].size(), false);
        vector<vector<bool>> visited(maze.size(), rv);
        return search(maze, {start[0], start[1]}, {destination[0], destination[1]}, visited);
    }
};