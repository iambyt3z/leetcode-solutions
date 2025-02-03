class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 1, prev2 = 1, res1 = 1, res2 = 1;

        for(int i=1; i<n; i++) {
            prev1 = prev1 * (nums[i] > nums[i-1]) + 1;
            prev2 = prev2 * (nums[i] < nums[i-1]) + 1;
            res1 = max(res1, prev1);
            res2 = max(res2, prev2);
        }

        return max(res1, res2);
    }
};