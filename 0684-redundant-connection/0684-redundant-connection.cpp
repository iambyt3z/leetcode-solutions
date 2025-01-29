class Solution {
public:
    int find(int curr, vector<int> &parent) {
        if(parent[curr] != curr)
            parent[curr] = find(parent[curr], parent);

        return parent[curr];
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent;
        for(int i=0; i<=n; i++)
            parent.push_back(i);

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if(pu == pv)
                return {u, v};

            if(pu < pv)
                parent[pv] = pu;
            else
                parent[pu] = pv;
        }

        return {};
    }
};