string Solution::countAndSay(int A) {
    
    if (A == 0) return 0;
    
    int sequence = 1;
    string ansSeq = "1";
    
    for (int  i = sequence; i < A; i++) {
        
        char current = '-';
        int currentNum = 0;
        string newSeq = "";
        
        for (int j = 0; j < ansSeq.size(); j++) {
            if (current == '-') {
               current = ansSeq[j]; 
               currentNum += 1;
            } else if (ansSeq[j] == current) {
                currentNum++;
            } else {
                string n = to_string(currentNum);
                newSeq += n;
                newSeq.push_back(current);
                current = ansSeq[j];
                currentNum = 1;
            }
        }
        string n = to_string(currentNum);
        newSeq += n;
        newSeq.push_back(current);
        ansSeq = newSeq;
    }
    
    return ansSeq;
}
