struct Node {
    char label;
    unordered_map<char, Node*> children;
    bool isEnd;
    Node(char l) : label(l), isEnd(false) {}
};

class Trie {
private:
    Node* start;
public:
    /** Initialize your data structure here. */
    Trie() {
        start = new Node('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* current = start;
        for (int i = 0; i < word.length(); i++) {
            char currentLetter = word[i];
            if (current->children.find(currentLetter) == current->children.end()) {
                current->children.emplace(currentLetter, new Node(currentLetter));
            }            
            current = current->children[currentLetter];
        }        
        current->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* current = start;
        
        for (int i = 0; i < word.size(); i++) {
            char currentLetter = word[i];
            
            if (current->children.find(currentLetter) == current->children.end()) return false;
            current = current->children[currentLetter];
        }
        
        return current->isEnd ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* current = start;
        
        for (int i = 0; i < prefix.size(); i++) {
            char currentLetter = prefix[i];
            
            if (current->children.find(currentLetter) == current->children.end()) return false;
            current = current->children[currentLetter];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */