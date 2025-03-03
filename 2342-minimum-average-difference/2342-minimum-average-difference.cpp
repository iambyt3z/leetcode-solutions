class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        for(int ni: nums) sum += ni;
        int n = nums.size();
        
        long long sum_curr = 0;
        int left_elements = 0;
        int res = -1;
        long long curr_avg = INT_MAX;
        
        for(int i=0; i<n; i++) {
            sum_curr += nums[i];
            left_elements++;
            long long left_avg, right_avg;

            left_avg = sum_curr / left_elements;

            if(i == n-1) right_avg = 0;
            else right_avg = (sum - sum_curr) / (n - left_elements);

            if(curr_avg > abs(left_avg - right_avg)) {
                curr_avg = abs(left_avg - right_avg);
                res = i;
            }
        }

        return (int) res;
    }
};