// TC: O(M + Nx) // Where M is tatol size of products and N is the searchWord length and x average product length
// MC: O(M)
class Solution {
public:
    class TrieNode {
        public:
            bool isEnd;
            TrieNode* next[26];
            TrieNode() {
                isEnd = false;
                fill(begin(next), end(next), nullptr);
            }
    };
    class Trie {
        public:
            TrieNode* root;
            Trie() {
                root = new TrieNode();
            }
            void insert(string &word) {
                auto curr = root;
                for(auto &ch: word) {
                    int rnk = ch - 'a';
                    if(curr -> next[rnk] == nullptr) {
                        curr -> next[rnk] = new TrieNode();
                    }
                    curr = curr -> next[rnk];
                }
                curr -> isEnd = true;
            }
    };
    // TC: O(M) // spending time for build trie
    Trie* buildTrie(vector<string>& products) {
        auto trie = new Trie();
        for(auto &product: products) {
            trie -> insert(product);
        };
        return trie;
    }
    void dfs(TrieNode* currNode, string &prefix, vector<string> &result) {
        if(currNode == nullptr || result.size() == 3) return;
        if(currNode -> isEnd) result.push_back(prefix);
        for(int i = 0; i < 26; i++) {
            if(currNode -> next[i] == nullptr) continue;
            prefix.push_back((char)(i + 'a'));
            dfs(currNode -> next[i], prefix, result);
            // backtrac
            prefix.pop_back();
        }
    }
    bool startsWith(vector<string> &suggestion, string &prefix) {
        int index = prefix.size() - 1;
        for(auto &word: suggestion) {
            if(word[index] != prefix.back()) return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto trie = buildTrie(products);
        vector<vector<string>> suggestions;
        string prefix = "";
        auto currNode = trie -> root;
        
        for(auto &sw: searchWord) {
            prefix.push_back(sw);
            vector<string> result;
            currNode = currNode ? currNode -> next[sw - 'a'] : nullptr;
            if(!suggestions.empty() && startsWith(suggestions.back(), prefix)) {
                suggestions.push_back(suggestions.back());
            } else {
                dfs(currNode, prefix, result);
                suggestions.push_back(result);
            }
        }
        return suggestions;
    }
};