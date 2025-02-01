class Solution {
public:
    int dp[201][201];

    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix) {
        if(dp[i][j] != -1)
            return dp[i][j];

        int res = 1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for(int d=0; d<4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];

            if( ii < 0 || ii >= n || jj < 0 || jj >= m || matrix[i][j] <= matrix[ii][jj] )
                continue;

            res = max(res, 1 + solve(ii, jj, n, m, matrix));
        }

        return dp[i][j] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res = max(res, solve(i, j, n, m, matrix));
            }
        }

        return res;
    }
};