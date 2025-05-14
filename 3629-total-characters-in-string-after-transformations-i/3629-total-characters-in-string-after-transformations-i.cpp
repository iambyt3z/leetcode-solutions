class Solution {
public:
    int mod = 1000000007;

    long long processDp(
        int i, int t,
        vector<int> &nums,
        vector<vector<long long>> &dp
    ) {
        if(t == 0)
            return dp[i][t] = 1;

        if(dp[i][t] != -1)
            return dp[i][t];

        long long res = 0LL;
        int ni = nums[i];

        for(int next_i = i+1; next_i <= i+ni; next_i++) {
            long long ri = processDp(next_i % 26, t-1, nums, dp);
            res = (res + ri) % mod;
        }
                
        return dp[i][t] = res;
    }

    int lengthAfterTransformations(string s, int t) {
        vector<int> nums(26, 1); nums[25] = 2;
        vector<vector<long long>> dp(26, vector<long long>(t+1, -1));
        int res = 0;

        for(int i=0; i<s.length(); i++) {
            int chi = (int) (s[i] - 'a');
            int ri = processDp(chi, t, nums, dp);
            res = (res + ri) % mod;
        }

        return res;
    }
};