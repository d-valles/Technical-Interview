class Solution {
public:
    struct Node {
        string word;
        int moves;
        Node(string x, int y) : word(x), moves(y) {}
    };
    
    int helper(string currentWord, unordered_map<string,bool>& hashMap, string endWord, vector<string>& wordList) {
        queue<Node> Q;
        Node current = Node(currentWord, 1);
        Q.push(current);
        
        while (!Q.empty()) {
            current = Q.front();
            Q.pop();
            cout<<current.word<<endl;
            
            if (current.word == endWord) {
                return current.moves;
            }
            
            for (int i = 0; i < current.word.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string newWord = current.word;
                    newWord[i] = 'a' + j;
                    if (hashMap.find(newWord) != hashMap.end() && !hashMap[newWord]) {
                        Node newNode = Node(newWord, current.moves + 1);
                        hashMap[newWord] = true;
                        Q.push(newNode);
                    }
                }
            }    
        }
        
        return 0;
    }
    
    unordered_map<string,bool> createMap(vector<string>&wordList) {
        unordered_map<string,bool> hashMap;
        for (int i = 0; i < wordList.size(); i++) {
            hashMap.emplace(wordList[i], false);
        }
        return hashMap;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> hashMap = createMap(wordList);
        if (beginWord == endWord || hashMap.find(endWord) == hashMap.end()) return 0;
        return helper(beginWord, hashMap, endWord, wordList);
    }
};

    