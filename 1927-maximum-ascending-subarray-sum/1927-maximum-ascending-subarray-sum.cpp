class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int curr = nums[0];

        for(int i=1; i<n; i++) {
            curr = (nums[i] > nums[i-1]) * curr + nums[i];
            res = max(res, curr);
        }

        return res;
    }
};