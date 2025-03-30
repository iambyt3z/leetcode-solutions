class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int n, vector<int> &comb, unordered_map<int, int> &cnt) {
        if(comb.size() == n) {
            res.push_back(comb);
            return ;
        }

        for(auto [k, v]: cnt) {
            if(v == 0)
                continue;

            comb.push_back(k);
            cnt[k]--;
            backtrack(n, comb, cnt);
            comb.pop_back();
            cnt[k]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto ni: nums) cnt[ni]++;
        vector<int> comb;
        backtrack(nums.size(), comb, cnt);
        return res;
    }
};