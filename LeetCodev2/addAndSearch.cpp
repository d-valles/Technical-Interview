struct Node {
    char label;
    bool isEnd;
    unordered_map<char,Node*> children;
    Node(char l) : label(l), isEnd(false) {}
};

class WordDictionary {
private:
    Node* start;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        start = new Node('*');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* current = start;
        for (int i = 0; i < word.size(); i++) {
            char currentLetter = word[i];
            if (current->children.find(currentLetter) == current->children.end())  {
                current->children.emplace(currentLetter, new Node(currentLetter));
            }
            current = current->children[currentLetter];
        }
        current->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node* current = start;
        return helper(current, 0, word);   
    }
    
    bool helper (Node* current, int index, string word) {
        if (current->isEnd && index == word.size()) return true;
        
        char letter = word[index];
        
        if (letter == '.') {
            bool isCorrect = false;
            for (auto it = current->children.begin(); it != current->children.end(); it++) {
                isCorrect = helper(it->second, index + 1, word);
                if (isCorrect) return true;
            }
        }
        else if (current->children.find(letter) != current->children.end()) {
            return helper(current->children[letter], index + 1, word);
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */