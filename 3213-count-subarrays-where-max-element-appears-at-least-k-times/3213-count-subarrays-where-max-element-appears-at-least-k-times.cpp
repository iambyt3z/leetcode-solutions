class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = -1;
        for(int ni: nums) 
            maxEle = max(maxEle, ni);

        int prefix = 0;
        unordered_map<int, int> ind;
        ind[0] = 0;

        long long res = 0;
        for(int i=0; i<n; i++) {
            prefix += (nums[i] == maxEle);
            int tar = prefix - k;

            if(ind.count(tar)) {
                res += ind[tar]+1;
            }

            ind[prefix] = i+1;
        }

        return res;
    }
};