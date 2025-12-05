/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Empty tree
        if (!root) return nullptr;
        
        // Found one of the target nodes
        if (root == p || root == q) return root;
        
        // Recursively search both subtrees
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
        
        // Both nodes found in different subtrees
        if (leftResult && rightResult) return root;
        
        // Both in left subtree
        if (leftResult) return leftResult;
        
        // Both in right subtree
        if (rightResult) return rightResult;
        
        // Not found
        return nullptr;
    }
};