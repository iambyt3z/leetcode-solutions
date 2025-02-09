class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long) n*(n-1)/2;
        unordered_map<int, long long> cnt;
        long long valid = 0;

        for(int i=n-1; i>=0; i--) {
            int curr = nums[i] - i;
            valid += cnt[curr];
            cnt[curr]++;
        }

        return total - valid;
    }
};