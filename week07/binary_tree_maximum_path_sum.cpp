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
// TC: O(N) // total number of nodes.
// MC: O(logN) 
class Solution {
public:
    int maxSum;
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxSum;
    }
private:
    int pathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftMax = max(pathSum(root -> left), 0);
        int rightMax = max(pathSum(root -> right), 0);
        maxSum = max(maxSum, (root -> val + leftMax + rightMax));
        return root -> val + max(leftMax, rightMax);
    }
};