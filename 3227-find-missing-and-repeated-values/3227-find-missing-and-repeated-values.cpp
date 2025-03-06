class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n*n, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int num = grid[i][j];
                int ind = num - 1;
                cnt[ind]++;
            }
        }

        vector<int> res = {0, 0};
        for(int i=0; i<n*n; i++) {
            if(cnt[i] == 0) res[1] = i+1;
            else if(cnt[i] == 2) res[0] = i+1;
        }

        return res;
    }
};