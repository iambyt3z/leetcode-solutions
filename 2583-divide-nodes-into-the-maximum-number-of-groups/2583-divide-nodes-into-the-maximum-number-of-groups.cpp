class Solution {
public:
    bool isBipartite(
        int curr_node, int curr_group,
        vector<int> &group, vector<vector<int>> &adj,
        vector<int> &nodes_covered
    ) {
        group[curr_node] = curr_group;
        nodes_covered.push_back(curr_node);

        for(auto next: adj[curr_node]) {
            if(group[next] == -1) {
                bool markNext = isBipartite(next, 1 - curr_group, group, adj, nodes_covered);
                if(!markNext) return false;
            }
            else if(group[next] == curr_group)
                return false;
        }

        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> group(n, -1);
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (group[i] != -1) continue;

            vector<int> component;
            if (!isBipartite(i, 0, group, adj, component)) {
                return -1;
            }

            int maxDist = 0;
            for (int u : component) {
                vector<int> dist(n, -1);
                queue<int> q;
                dist[u] = 0;
                q.push(u);
                int current_max = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (int v : adj[curr]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[curr] + 1;
                            if (dist[v] > current_max) {
                                current_max = dist[v];
                            }
                            q.push(v);
                        }
                    }
                }

                maxDist = max(maxDist, current_max);
            }

            res += maxDist + 1;
        }

        return res;
    }
};