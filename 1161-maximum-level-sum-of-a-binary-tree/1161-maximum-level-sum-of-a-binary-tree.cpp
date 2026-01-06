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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int res = -1;
        int currLevel = 0;

        while(q.size()) {
            int currSize = q.size();
            int currSum = 0;
            currLevel++;

            while(currSize--) {
                TreeNode* currNode = q.front();
                q.pop();
                
                currSum += currNode->val;

                if(currNode->left != nullptr)
                    q.push(currNode->left);

                if(currNode->right != nullptr)
                    q.push(currNode->right);
            }

            if(currSum > maxSum) {
                maxSum = currSum;
                res = currLevel;
            }
        }

        return res;
    }
};