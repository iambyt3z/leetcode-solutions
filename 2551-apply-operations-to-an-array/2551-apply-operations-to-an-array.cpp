class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        for(int i=0; i<n-1; i++) {
            if(nums[i] == 0)
                continue;

            if(nums[i] == nums[i+1]) {
                nums[i+1] = 0;
                res.push_back(2 * nums[i]);
            }

            else
                res.push_back(nums[i]);
        }

        if(nums[n-1] != 0)
            res.push_back(nums[n-1]);

        while(res.size() < n)
            res.push_back(0);

        return res;
    }
};