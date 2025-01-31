#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dfs(int i, int j, int n, int id, vector<vector<int>>& grid, vector<vector<int>>& islandId) {
        islandId[i][j] = id;
        int res = 1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (ii >= 0 && ii < n && jj >= 0 && jj < n && grid[ii][jj] == 1 && islandId[ii][jj] == -1) {
                res += dfs(ii, jj, n, id, grid, islandId);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> islandId(n, vector<int>(n, -1));
        vector<int> areas = {0}; // areas[0] is for water (id 0)
        int id = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && islandId[i][j] == -1) {
                    int area = dfs(i, j, n, id, grid, islandId);
                    areas.push_back(area);
                    ++id;
                } else if (grid[i][j] == 0) {
                    islandId[i][j] = 0;
                }
            }
        }

        int res = *max_element(areas.begin(), areas.end());
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int current = 1;
                    for (int d = 0; d < 4; ++d) {
                        int ii = i + dx[d];
                        int jj = j + dy[d];
                        if (ii >= 0 && ii < n && jj >= 0 && jj < n) {
                            int neighborId = islandId[ii][jj];
                            if (neighborId != 0 && !seen.count(neighborId)) {
                                current += areas[neighborId];
                                seen.insert(neighborId);
                            }
                        }
                    }
                    res = max(res, current);
                }
            }
        }

        return res;
    }
};