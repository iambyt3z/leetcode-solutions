class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int prefix = 0;
        vector<int> v(n+1, 0);

        for(auto &q: queries) {
            int l = q[0], r = q[1];
            v[l]++; v[r+1]--;
        }

        for(int i=0; i<n; i++) {
            prefix += v[i];
            if(prefix < nums[i])
                return false;
        }

        return true;
    }
};