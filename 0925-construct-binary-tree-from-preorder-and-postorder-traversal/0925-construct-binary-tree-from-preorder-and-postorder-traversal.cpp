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
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int &preInd, int left, int right) {
        int currVal = preorder[preInd];
        TreeNode* curr = new TreeNode(currVal);
        preInd++;

        if(preInd >= preorder.size() || left == right)
            return curr;

        int postInd = -1;
        for(int i=left; i<right; i++) {
            if(postorder[i] == preorder[preInd]) {
                postInd = i;
                break;
            }
        }

        if(postInd == -1)
            return curr;

        int leftTreeElem = (postInd - left + 1);
        int rightTreeElem = (right - postInd - 1);
        
        if(leftTreeElem)
            curr->left = construct(preorder, postorder, preInd, left, postInd);

        if(rightTreeElem)
            curr->right = construct(preorder, postorder, preInd, postInd+1, right-1);

        return curr;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preInd = 0;
        return construct(preorder, postorder, preInd, 0, postorder.size()-1);
    }
};