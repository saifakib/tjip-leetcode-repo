/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// TC: O(N) // number of nodes
// MC: O(H) // tree height 
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> findLeaves(TreeNode* root) {
        findDepth(root);
        return result;
    }
private:
    int findDepth(TreeNode* root) {
       if(root == nullptr) return 0;
        int depth = max(findDepth(root -> left), findDepth(root -> right));
        if (depth >= result.size()) result.resize(depth + 1);
        result[depth].push_back(root -> val);
        return depth + 1;
    }
};