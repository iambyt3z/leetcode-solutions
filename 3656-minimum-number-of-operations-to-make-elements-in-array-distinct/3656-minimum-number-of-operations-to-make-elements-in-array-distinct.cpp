class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int ni: nums) umap[ni]++;
        int res = 0, i = 0, n = nums.size();
        int count = n;

        while(i < n) {
            if(count == umap.size())
                return res;

            int t = 0;
            while(i < n && t < 3) {
                umap[nums[i]]--;
                if(umap[nums[i]] == 0)
                    umap.erase(nums[i]);
                
                count--;
                i++;
                t++;
            }

            res++;
        }

        return res;
    }
};