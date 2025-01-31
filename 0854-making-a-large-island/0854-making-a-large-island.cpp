class Solution {
public:
    int dfs(
        int i, int j, int n, int id,
        vector<vector<int>> &grid,
        vector<vector<int>> &islandId
    ) {
        islandId[i][j] = id;

        int res = 1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for(int d=0; d<4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];

            if(ii < 0 || ii >= n || jj < 0 || jj >= n || grid[ii][jj] == 0 || islandId[ii][jj] == id)
                continue;

            res += dfs(ii, jj, n, id, grid, islandId);
        }

        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> islandId(n, vector<int>(n, -1));
        vector<int> areas; areas.push_back(0);
        int id = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) islandId[i][j] = 0;
                if(islandId[i][j] != -1) continue;

                int area = dfs(i, j, n, id, grid, islandId);
                areas.push_back(area);
                id++;
            }
        }

        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int id = islandId[i][j];      
                if(id == 0) continue;

                res = max(res, areas[id]);
                vector<int> dx = {-1, 1, 0, 0};
                vector<int> dy = {0, 0, 1, -1};

                for(int d=0; d<4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];

                    if(ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                    if(islandId[ii][jj] != 0) continue;

                    int increased_area = 1;
                    vector<int> ddx = {-1, 1, 0, 0};
                    vector<int> ddy = {0, 0, 1, -1};
                    unordered_map<int, int> covered;

                    for(int dd=0; dd<4; dd++) {
                        int iii = ii + ddx[dd];
                        int jjj = jj + ddy[dd];
                        if(iii < 0 || iii >= n || jjj < 0 || jjj >= n) continue;
                        if(islandId[iii][jjj] == 0 || islandId[iii][jjj] == id) continue;
                        if(covered.count(islandId[iii][jjj]) == 1) continue;

                        int id2 = islandId[iii][jjj];
                        increased_area += areas[id2];
                        covered[id2]++;
                    }

                    covered.clear();
                    res = max(res, areas[id] + increased_area);
                }
            }
        }

        return ( (res > 0) ? res : 1 );
    }
};