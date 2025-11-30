class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        int n = nums.size();
        unordered_map<int, vector<int>> ind;
        vector<long long> ps;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum % p;
            ind[rem].push_back(i);
            ps.push_back(sum);
        }

        if(sum % p == 0)
            return 0;

        int res = INT_MAX;
        for(int i=0; i<n; i++) {
            long long sum_left = ps[i];
            long long sum_right = sum - sum_left;

            int right_sum_rem = sum_right % p;
            int target_rem = (p - right_sum_rem) % p;

            if(right_sum_rem == 0 && sum_right != 0)
                res = min(res, i+1);

            if(ind.count(target_rem) == 0) {
                continue;
            }

            auto &indexes_target_rem = ind[target_rem];
            int left = 0, right = indexes_target_rem.size()-1;
            int ind_to_find = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(indexes_target_rem[mid] < i) {
                    ind_to_find = indexes_target_rem[mid];
                    left = mid+1;
                }

                else {
                    right = mid-1;
                }
            }

            if(ind_to_find == -1)
                continue;

            int temp_res = (i - ind_to_find);
            res = min(res, temp_res);
        }

        if(res == INT_MAX)
            return -1;

        return res;
    }
};