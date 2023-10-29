
// TC: 0(|s| + |t|)
// MC: 0(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fs (256, 0);
        for(auto c: s) {
            fs[c]++;
        }

        vector<int> ft (256, 0);
        for(auto c: t) {
            ft[c]++;
        }

        return fs == ft;
    }
};