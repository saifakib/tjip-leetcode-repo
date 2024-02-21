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
// TC: O(N) // where N is the number of nodes in the binary tree
// MC: O(N)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> store;
        queue<pair<TreeNode*, int>> Q;
        if(root != nullptr) Q.push({root, 0});

        while(!Q.empty()) {
            int levelSize = Q.size();
            while(levelSize--) {
                auto [node, val] = Q.front(); Q.pop();
                store[val].push_back(node -> val);
                if(node -> left) Q.push({node -> left, val - 1});
                if(node -> right) Q.push({node -> right, val + 1});
            }
        }
        vector<vector<int>>vOrder;
        for(auto i:store) {
            vOrder.push_back(i.second);
        }
        return vOrder;
    }
};