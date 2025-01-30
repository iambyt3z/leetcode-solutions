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

    vector<vector<int>> calcMinDist(int n, vector<vector<int>> &adj) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for(int u=0; u<n; u++) {
            for(auto v: adj[u]) {
                dist[u][v] = min(dist[u][v], 1);
            }
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        return dist;
    }  

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        int e = edges.size();

        for(int i=0; i<e; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> group(n, -1);
        vector<vector<int>> minDist = calcMinDist(n, adj);
        int res = 0;

        for(int i=0; i<n; i++) {
            if(group[i] != -1)
                continue;

            vector<int> nodes_covered;
            bool isBip = isBipartite(i, 0, group, adj, nodes_covered);

            if(!isBip)
                return -1;

            int ri = 0;
            int len = nodes_covered.size();
            for(int i=0; i<len-1; i++) {
                for(int j=i+1; j<len; j++) {
                    int u = nodes_covered[i];
                    int v = nodes_covered[j];
                    ri = max(ri, minDist[u][v]);
                }
            }

            res += (ri+1);
        }

        return res;
    }
};