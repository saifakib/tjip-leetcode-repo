class Solution {
private:
    void toConstructBST(vector<int>& preorder, int &currIndex, int l_min, int r_max) {
        if(currIndex == preorder.size()) return;
        int val = preorder[currIndex];
        if(val <= l_min ||val >= r_max) return;
        currIndex++;
        toConstructBST(preorder, currIndex, l_min, val);
        toConstructBST(preorder, currIndex, val, r_max);
    }
public:
    // TC: O(N) // N = |preorder|
    // MC: O(N) // Stack cost
    bool verifyPreorder(vector<int>& preorder) {
        int currIndex = 0;
        int l_min = INT_MIN;
        int r_max = INT_MAX;
        toConstructBST(preorder, currIndex, l_min, r_max);
        return currIndex == preorder.size();
    }
};