class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for(int i=0; i<n; i++) drops += (nums[i] < nums[(i-1+n) % n]);
        return (drops <= 1);
    }
};