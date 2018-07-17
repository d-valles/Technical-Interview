class Solution {
public:
    void addCurrent(int times, char number, string& newSequence) {
        newSequence += to_string(times);
        newSequence += number;
    }
    
    string countAndSay(int n) {
        string sequence = "1";
        int term = 1;       
        for (int i = term; i < n; i++) {
            string newSequence = "";
            char current = sequence[0];
            int currentTimes = 1;
            
            for (int j = 1; j < sequence.size(); j++) {
                if (sequence[j] == current) {
                    currentTimes++;
                } else {
                    addCurrent(currentTimes, current, newSequence);              
                    currentTimes = 1;
                    current = sequence[j];             
                }
            }
            
            addCurrent(currentTimes, current, newSequence);          
            sequence = newSequence;
        }
        return sequence;
    }
};