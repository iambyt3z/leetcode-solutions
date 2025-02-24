class Solution {
public:
    bool dfs(int curr, int d, unordered_map<int, vector<int>> &adj, vector<int> &visBob) {
        visBob[curr] = 0;

        if(curr == 0) {
            visBob[curr] = d;
            return true;
        }

        for(auto next: adj[curr]) {
            if(visBob[next] != -1)
                continue;

            if(dfs(next, d+1, adj, visBob)) {
                visBob[curr] = d;
                return true;
            }
        }

        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        unordered_map<int, vector<int>> adj;
        
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visBob(n, -1);
        dfs(bob, 1, adj, visBob);

        int res = INT_MIN;
        vector<bool> visAlice(n, false);
        queue<tuple<int, int, int>> q;
        q.push({ 0, 1, amount[0] });
        visAlice[0] = true;

        while(q.size()) {
            auto [curr, d, inc] = q.front();
            q.pop();

            int nextNodes = 0;
            for(auto next: adj[curr]) {
                if(visAlice[next])
                    continue;

                int nextD = d+1;
                int nextInc;

                if(visBob[next] <= 0 || visBob[next] > nextD) { // Alice visited first
                    nextInc = inc + amount[next];
                } else if(visBob[next] == nextD) { // Alice and bob visited at the same time
                    nextInc = inc + amount[next] / 2;
                } else if(visBob[next] < nextD) {  // Alice visited later
                    nextInc = inc;
                }

                q.push({ next, nextD, nextInc });
                visAlice[next] = true;
                nextNodes++;
            }

            if(nextNodes == 0)
                res = max(res, inc);
        }

        return res;
    }
};