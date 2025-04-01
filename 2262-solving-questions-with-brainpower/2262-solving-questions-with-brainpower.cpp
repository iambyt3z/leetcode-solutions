class Solution {
public:
    long long dp[100001];

    long long solve(int i, int n, vector<vector<int>> &q) {
        if(i >= n)
            return 0LL;

        if(dp[i] != -1)
            return dp[i];

        long long res = solve(i+1, n, q);
        res = max(res, q[i][0] + solve(i+1+q[i][1], n, q));
        return dp[i] = res;
    }

    long long mostPoints(vector<vector<int>> &q) {
        memset(dp, -1LL, sizeof(dp));
        return solve(0, q.size(), q);
    }
};