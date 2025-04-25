class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long prefix = 0, res = 0;
        unordered_map<int, int> cnt;
        cnt[0]++;

        for(int i=0; i<n; i++) {
            prefix += (nums[i] % m == k);
            int a = prefix % m;
            int b1 = a - k;
            int b2 = a - k + m;

            res += (b1 >= 0) * cnt[b1] + (b2 >= 0) * cnt[b2];
            cnt[a]++;
        }

        return res;
    }
};