class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        unordered_map<int, queue<int>> ind;
        vector<int> res(n, 0);
        for(int i=0; i<n; i++) ind[nums[i]].push(i);

        sort(nums.begin(), nums.end());

        vector<int> tmp_nums, tmp_ind;
        tmp_nums.push_back(nums[0]);
        tmp_ind.push_back(ind[nums[0]].front());
        ind[nums[0]].pop();

        for(int i=1; i<n; i++) {
            if(nums[i] - nums[i-1] <= limit) {
                tmp_nums.push_back(nums[i]);
                tmp_ind.push_back(ind[nums[i]].front());
                ind[nums[i]].pop();
                continue;
            }

            int len = tmp_ind.size();
            sort(tmp_ind.begin(), tmp_ind.end());
            for(int j=0; j<len; j++) res[tmp_ind[j]] = tmp_nums[j];

            tmp_ind.clear();
            tmp_nums.clear();

            tmp_nums.push_back(nums[i]);
            tmp_ind.push_back(ind[nums[i]].front());
            ind[nums[i]].pop();
        }

        sort(tmp_ind.begin(), tmp_ind.end());
        int len = tmp_ind.size();
        for(int j=0; j<len; j++) res[tmp_ind[j]] = tmp_nums[j];

        return res; 
    }
};