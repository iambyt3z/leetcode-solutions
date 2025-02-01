class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool res = true;

        for(int i=0; i<n-1; i++) {
            res = res && ( ((nums[i]%2) ^ (nums[i+1]%2)) == 1 );
        }

        return res;
    }
};