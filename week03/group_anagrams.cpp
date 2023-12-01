// TC: 0(SlogL) where S total length of character and L avarage length of a string
// SC: 0(N) where N total length of strs.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto str: strs) {
            string original_str = str; 
            sort(str.begin(), str.end());           // 0(LlogL) L avarage length of a string
            groups[str].push_back(original_str);
        }

        vector<vector<string>> group_anagrams;

        for(auto& group: groups) {
            group_anagrams.push_back(move(group.second));
        }

        return group_anagrams;
    }
};