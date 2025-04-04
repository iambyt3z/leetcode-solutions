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
    int maxDepth;
    TreeNode* result;

    int solve(int currDepth, TreeNode* curr) {
        if(curr == nullptr) {
            maxDepth = max(maxDepth, currDepth);
            return currDepth;
        }

        int left = solve(currDepth + 1, curr->left);
        int right = solve(currDepth + 1, curr->right);

        if(left == right && left == maxDepth)
            result = curr;

        return max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        result = nullptr;
        maxDepth = 0;
        solve(0, root);
        return result;
    }
};