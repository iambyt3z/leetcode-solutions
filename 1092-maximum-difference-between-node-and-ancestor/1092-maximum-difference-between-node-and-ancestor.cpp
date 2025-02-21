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
class Solution {
public:
    int res = 0;

    void dfs(TreeNode* curr, int maxVal, int minVal) {
        if(curr == nullptr)
            return ;

        res = max(res, abs(maxVal - curr->val));
        res = max(res, abs(minVal - curr->val));

        int nextMaxVal = max(maxVal, curr->val);
        int nextMinVal = min(minVal, curr->val);

        if(curr->left) dfs(curr->left, nextMaxVal, nextMinVal);
        if(curr->right) dfs(curr->right, nextMaxVal, nextMinVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return res;
    }
};