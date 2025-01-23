class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        unordered_map<int, vector<int>> adj;
        vector<int> r(n, -1), c(m, -1);

        for(int i=0; i<n; i++) {
            for(int  j=0; j<m; j++) {
                if(grid[i][j] == 0)
                    continue;

                int u = i * m + j;

                if(r[i] != -1) {
                    int v = r[i];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }

                if(c[j] != -1) {
                    int v = c[j];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }

                r[i] = u;
                c[j] = u;
            }
        }

        return adj.size();
    }
};