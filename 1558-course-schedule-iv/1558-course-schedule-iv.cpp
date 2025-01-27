class Solution {
public:
    bool dfs(
        int curr, int target, 
        vector<vector<int>> &prereq, 
        vector<vector<int>> &dp
    ) {
        if(dp[curr][target] != -1)
            return dp[curr][target];

        if(curr == target)
            return true;

        bool res = false;
        for(int next: prereq[curr]) {
            bool ri = dfs(next, target, prereq, dp);
            res |= ri;
        }

        return dp[curr][target] = res;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> prereq(n, vector<int>());

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            prereq[u].push_back(v);
        }
        
        vector<bool> res;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(auto q: queries) {
            int src = q[0], target = q[1];
            bool ri = dfs(src, target, prereq, dp);
            res.push_back(ri);
        }

        return res;
    }
};