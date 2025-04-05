class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int len = nums.size();

        for(int state = 0; state < pow(2, len); state++) {
            // cout << "state = " << state << endl;
            int curr = 0;

            for(int i=0; i<len; i++) {
                int bitmask = (1 << i);
                if(bitmask & state) {
                    curr ^= nums[len-1-i];
                    // cout << "Added: " << nums[len-1-i] << endl;
                }
            }

            res += curr;
            // cout << "curr = " << curr << endl;
        }

        return res;
    }
};