// TC: 0(M(N-1)) M is the length of haystack and N is the length of needle
// SC: 0(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;

        for(int i = 0; i < haystack.size();  i++) {

            if(haystack[i] == needle[index]) index++;
            else {
                // reverse back to next occurrence point 
                i = i - index;
                index = 0;
            };

            if(index == needle.size()) return i - (index-1);

            if(index == 0 && (haystack.size() - i) < needle.size())  return -1;
        }
        return -1;
    }
};