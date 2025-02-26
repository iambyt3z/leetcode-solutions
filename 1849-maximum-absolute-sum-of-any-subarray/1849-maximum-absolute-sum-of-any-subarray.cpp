class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        long long prevMax = INT_MIN, prevMin = INT_MAX;
        long long res = 0;

        for(int i=0; i<n; i++) {
            prevMax = max((long long) nums[i], prevMax + nums[i]);
            prevMin = min((long long) nums[i], prevMin + nums[i]);
            res = max(res, abs(prevMax));
            res = max(res, abs(prevMin));
        }

        return res;
    }
};