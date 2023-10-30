// TC: 0(S) where S total number of characters
// SC: 0(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix_string ("");

        string base_word = strs[0];
        int index = 0;
        while(index < base_word.size()) {
            for(int i=1; i<strs.size(); i++) {
                if(base_word[index] != strs[i][index]) return prefix_string;
            }
            prefix_string.push_back(base_word[index]);
            index++;
        }

        return prefix_string;
    }
};