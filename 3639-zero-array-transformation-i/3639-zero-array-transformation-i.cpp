class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int prefix = 0;
        vector<int> v(n+1, 0);

        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
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