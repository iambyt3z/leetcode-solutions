class Solution {
public:
    vector<int> helper(unordered_map<int, vector<int>> &adj, int k) {
        int n = adj.size();
        vector<int> res(n, 0);

        for(int i=0; i<n; i++) {
            vector<int> vis(n, false);
            queue<pair<int, int>> q;
            q.push({i, 0});
            vis[i] = true;
            int ri = 0;

            while(q.size()) {
                auto [curr, dis] = q.front();
                q.pop();
                ri += (dis <= k);

                for(int next: adj[curr]) {
                    if(vis[next]) continue;
                    q.push({ next, dis+1 });
                    vis[next] = true;
                }
            }

            res[i] = ri;
        }

        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> adj1, adj2;

        for(auto &e: edges1) {
            int u = e[0], v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto &e: edges2) {
            int u = e[0], v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> v1 = helper(adj1, k);
        vector<int> v2 = helper(adj2, k-1);
        int max_v2 = *max_element(v2.begin(), v2.end());

        vector<int> res;
        for(int vi: v1) res.push_back(vi+max_v2);

        return res;
    }
};