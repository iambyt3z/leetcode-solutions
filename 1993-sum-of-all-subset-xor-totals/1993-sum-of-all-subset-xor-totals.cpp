class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int len = nums.size();

        for(int state = 0; state < pow(2, len); state++) {
            int curr = 0;

            for(int i=0; i<len; i++) {
                int bitmask = (1 << i);
                curr ^= ((bitmask & state) != 0) * nums[len-1-i];
            }

            res += curr;
        }

        return res;
    }
};