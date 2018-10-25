class Solution {
    struct Room {
         int row;
         int col;
         int value;
         Room (int r, int c, int val) : row(r), col(c), value(val) {}
    };
    
public:
    void findGates(queue<Room*> &queueOfRooms, vector<vector<int>>& rooms) {
        for (int rows = 0; rows < rooms.size(); rows++) {
            for (int col = 0; col < rooms[rows].size(); col++) {
                if (rooms[rows][col] == 0) {
                    queueOfRooms.push(new Room(rows, col, 0));
                }
            }
        }
    }
    
    bool isValid(vector<vector<int>>& rooms, int row, int col) {
        if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size()) return false;
        return true;
    }
    
    void updateRoomsNearMe(Room* current, queue<Room*> &queueOfRooms, vector<vector<int>>& rooms) {
        if (isValid(rooms, current->row + 1, current->col) && (rooms[current->row+1][current->col] == INT_MAX ||
            rooms[current->row+1][current->col] > current->value + 1)) {
            
            rooms[current->row+1][current->col] = current->value + 1;
            queueOfRooms.push(new Room(current->row + 1, current->col, current->value+1));
        }
        if (isValid(rooms, current->row - 1, current->col) && (rooms[current->row-1][current->col] == INT_MAX ||
            rooms[current->row-1][current->col] > current->value + 1)) {
            
             rooms[current->row-1][current->col] = current->value + 1;
            queueOfRooms.push(new Room(current->row - 1, current->col, current->value+1));
        }
        if (isValid(rooms, current->row, current->col + 1) && (rooms[current->row][current->col+ 1] == INT_MAX ||
            rooms[current->row][current->col+ 1] > current->value + 1)) {
            
              rooms[current->row][current->col +1] = current->value + 1;
            queueOfRooms.push(new Room(current->row, current->col + 1, current->value+1));
        }
        if (isValid(rooms, current->row, current->col - 1) && (rooms[current->row][current->col - 1] == INT_MAX ||
            rooms[current->row][current->col - 1] > current->value + 1)) {
            
              rooms[current->row][current->col-1] = current->value + 1;
            queueOfRooms.push(new Room(current->row, current->col-1, current->value+1));
        }
    }
    
    void findClosestGates(queue<Room*> &queueOfRooms, vector<vector<int>>& rooms) {
        while (!queueOfRooms.empty()) {
            Room* current = queueOfRooms.front();
            queueOfRooms.pop();
            updateRoomsNearMe(current, queueOfRooms, rooms);
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<Room*> queueOfRooms;
        findGates(queueOfRooms, rooms);
        findClosestGates(queueOfRooms, rooms);
    }
};