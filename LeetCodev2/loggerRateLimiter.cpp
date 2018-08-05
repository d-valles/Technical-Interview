class Logger {
private:
    unordered_map<string,int> hashMap;  
public:
    /** Initialize your data structure here. */
    Logger() {

    }
    
    bool isValid(int timestamp, int lastTimestamp) {
        if (timestamp >= lastTimestamp + 10) return true;
        return false;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if (hashMap.find(message) == hashMap.end() 
            || hashMap.find(message) != hashMap.end() 
            && isValid(timestamp, hashMap[message])) {
            hashMap[message] = timestamp;
            return true;
        }
              
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */