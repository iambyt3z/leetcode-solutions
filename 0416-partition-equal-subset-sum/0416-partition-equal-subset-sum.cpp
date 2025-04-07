class Solution {
public:
    int dp[201][20001];

    bool solve(int i, int d, vector<int> &nums) {
        if(i == nums.size() && d != 0)
            return dp[i][d] = false;

        if(d == 0)
            return dp[i][d] = true;
        
        // cout << i << " " << d << " " << nums.size() << endl;
        if(dp[i][d] != -1)
            return dp[i][d];

        int res = solve(i+1, d, nums);
        if(nums[i] <= d) res |= solve(i+1, d-nums[i], nums);
        return dp[i][d] = res;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int ni: nums) sum += ni;
        if(sum%2) return false;

        int target = sum / 2;
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums);
    }
};