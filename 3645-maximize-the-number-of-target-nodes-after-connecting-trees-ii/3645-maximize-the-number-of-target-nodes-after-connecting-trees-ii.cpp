class Solution {
public:
    vector<int> helper(unordered_map<int, vector<int>> &adj, bool findOdd) {
        int n = adj.size();
        vector<int> vis(n, -1);
        queue<pair<int, int>> q;
        int evenCount = 0, oddCount = 0;
        q.push({ 0, 0 });
        vis[0] = 0;

        while(q.size()) {
            auto [curr, d] = q.front();
            q.pop();

            evenCount += (d%2 == 0);
            oddCount += (d%2 == 1);

            for(int next: adj[curr]) {
                if(vis[next] != -1) continue;
                q.push({ next, d+1 });
                vis[next] = d+1;
            }
        }

        vector<int> res;
        for(int i=0; i<n; i++) {
            int ri;
            if(vis[i] % 2 == 0)
                ri = findOdd * oddCount + (1 - findOdd) * evenCount;
            else
                ri = findOdd * evenCount + (1 - findOdd) * oddCount;

            res.push_back(ri);
        }

        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        vector<int> v1 = helper(adj1, false);
        vector<int> v2 = helper(adj2, true);
        int max_v2 = *max_element(v2.begin(), v2.end());
        vector<int> res;

        for(auto vi: v1)
            res.push_back(vi + max_v2);

        return res;
    }
};