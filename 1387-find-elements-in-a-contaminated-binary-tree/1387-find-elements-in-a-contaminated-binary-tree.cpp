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
class FindElements {
private:
    unordered_map<int, bool> nums;

    void dfs(TreeNode* curr, int val) {
        if(curr == nullptr)
            return ;

        curr->val = val;
        nums[val] = true;

        if(curr->left) dfs(curr->left, val*2+1);
        if(curr->right) dfs(curr->right, val*2+2);
    }

public:
    FindElements(TreeNode* root) {
        nums.clear();
        dfs(root, 0);
    }
    
    bool find(int target) {
        return nums[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
