class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, -1), rightMax(n, -1);
        int left = nums[0], right = nums[n-1];
        
        leftMax[0] = nums[0];
        rightMax[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            leftMax[i] = left;
            left = max(left, nums[i]);
        }

        for(int i=n-2; i>=0; i--) {
            rightMax[i] = right;
            right = max(right, nums[i]);
        }

        long long res = 0LL;
        for(int i=1; i<=n-2; i++)
            res = max( res, (long long) (leftMax[i] - nums[i]) * rightMax[i] );

        return res;
    }
};