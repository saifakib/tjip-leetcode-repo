class Solution {
private: 
    vector<int> index_of[26];
    // TC: 0(|ref| * logS);
    bool isSubSeq(string &s, string &ref) {
        int last = -1;
        for(int i = 0; i < ref.size(); i++) {
            int index = ref[i] - 'a';
            // 0(logS) // note: maximum size of base string for an vector
            int next = upper_bound(index_of[index].begin(), index_of[index].end(), last) - index_of[index].begin();
            if(next == index_of[index].size()) return false;
            last = index_of[index][next];
        }
        return true;
    }
public:
    // TC: O(|S| + WlogS) // where W = total number of characters of all string from words. 
    int numMatchingSubseq(string s, vector<string>& words) {
        // TC: 0(|S|);
        for(int i = 0; i < s.size(); i++) {
            index_of[s[i] - 'a'].push_back(i);
        }

        int count = 0;
        // TC: 0(words * (|ref| * logS))
        for(auto word: words) {
            count += isSubSeq(s, word);
        };

        return count;
    }
};