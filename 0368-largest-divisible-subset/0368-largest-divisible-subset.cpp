class Solution {
public:
    int dp[1001][1001];
    bool choice[1001][1001];

    int solve(int last_ele, int i, int n, vector<int> &nums) {
        if(i == n)
            return dp[last_ele][i] = 0;

        if(dp[last_ele][i] != -1)
            return dp[last_ele][i];

        int res1 = solve(last_ele, i+1, n, nums);
        int res2 = -1;

        if(last_ele == 0 || nums[last_ele-1] % nums[i] == 0)
            res2 = 1 + solve(i+1, i+1, n, nums);

        if(res2 > res1)
            choice[last_ele][i] = 1;

        return dp[last_ele][i] = max(res1, res2);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        memset(dp, -1, sizeof(dp));
        memset(choice, false, sizeof(choice));
        cout << solve(0, 0, n, nums) << endl << endl;
        vector<int> res;

        int i=0, j=0;
        while(j < n) {
            if(choice[i][j]) {
                res.push_back(nums[j]);
                i = j+1;
                j++;
            }

            else {
                j++;
            }
        }

        return res;
    }
};