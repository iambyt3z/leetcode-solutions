class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt = {0, 0, 0};
        for(int ni: nums) cnt[ni]++;

        for(int i=0; i<nums.size(); i++) {
            if(cnt[0]) {
                nums[i] = 0;
                cnt[0]--;
                continue;
            } 
            
            else if(cnt[1]) {
                nums[i] = 1;
                cnt[1]--;
                continue;
            }
            
            else {
                nums[i] = 2;
                cnt[2]--;
                continue;
            }
        }
    }
};