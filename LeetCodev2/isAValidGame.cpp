struct Room {
    int id;
    bool isLocked;
    bool hasTreasure;
    vector<Room*> doors;
    Room* key;
    Room(int i) : id(i), isLocked(false), hasTreasure(false), key(NULL) {} 
};

void gotKeyOfLockedDoor(queue<Room*> &roomsAvailable, unordered_set<room>& lockedRooms, Room* key) {
    if (lockedRooms.find(key)) {
        roomsAvailable.push(key);
    }
}

bool canGetTreasure(Room* start) {
    unoredered_set<room> visited;
    unordered_set<room> hasKeys;
    unordered_set<room> lockedRooms;
    queue<Room*> roomsAvailable;
    roomsAvailable.push(start);

    while(!roomsAvailable.empty()) {
        Room* current = roomsAvailable.front();
        roomsAvailable.pop();

        visited.emplace(current);

        if (current.hasTreasure) return true;

        if (current.key) {
            gotKeyOfLockedDoor(roomsAvailable, lockedRooms, current.key);
            hasKeyFor(key);
        }

        for (int i = 0; i < current.doors.size(); i++) {
            Room* optionDoor = current.doors[i];

            if (visited.find(optionDoor)) {
                continue;
            }

            if (optionDoor.isLocked && hasKeyFor.find(optionDoor)) {
                roomsAvailable.push(optionDoor);
            } else if(optionDoor.isLocked) {
                lockedRooms.push(optionDoor);
            } else {
                roomsAvailable.push(optionDoor);
            }
        }
    }

    return false;
}

bool isAValidGame(Room* start) {
    if (!start && start.lock) return false
    return canGetTreasure(start);
}