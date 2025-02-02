class Trie {
public:
    class TrieNode {
    public:
        bool isEnd;
        unordered_map<int, TrieNode*> next;
        TrieNode() {
            isEnd = false;
        }
    };
    TrieNode* root;
    Trie() {
       root = new TrieNode(); 
    }
    
    // TC: O(M) // M is the size of string
    // MC: O(M)
    void insert(string word) {
        auto curr = root;
        for(char &w: word) {
            int rnk = w - 'a';
            if(curr -> next[rnk] == nullptr) {
                curr -> next[rnk] = new TrieNode();
            }
            curr = curr -> next[rnk];
            //curr -> cnt++;
        }
        curr -> isEnd = true;
    }
    
    // TC: O(M) 
    // MC: O(1)
    bool search(string word, bool isPrefix = false) {
        auto curr = root;
        for(char &w: word) {
            int rnk = w - 'a';
            if(curr -> next[rnk] == nullptr) return false;
            curr = curr -> next[rnk];
        }
        return isPrefix || (curr && curr -> isEnd);
    }
    
    // TC: O(M) 
    // MC: O(1)
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */