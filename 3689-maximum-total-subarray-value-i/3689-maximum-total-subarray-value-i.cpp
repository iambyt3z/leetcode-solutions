class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxN = INT_MIN, minN = INT_MAX;
        for(int ni: nums) {
            maxN = max(ni, maxN);
            minN = min(ni, minN);
        }

        return (long long) (maxN - minN) * k;
    }
};