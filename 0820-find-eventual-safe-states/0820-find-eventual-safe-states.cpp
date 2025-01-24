class Solution {
public:
    bool isSafe(
        int node, vector<vector<int>> &graph, 
        vector<int> &isSafeNode, vector<bool> &vis
    ) {
        if(isSafeNode[node] != -1)
            return isSafeNode[node];

        vis[node] = true;

        if(graph[node].size() == 0) {
            isSafeNode[node] = 1;
            return true;
        }

        bool isNodeSafe = true;

        for(int ni: graph[node]) {
            if(vis[ni] && isSafeNode[ni] == -1) {
                isNodeSafe = false;
                break;
            }

            isNodeSafe &= isSafe(ni, graph, isSafeNode, vis);
        }

        return isSafeNode[node] = isNodeSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> isSafeNode(n, -1);
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            bool isCurrSafe = isSafe(i, graph, isSafeNode, vis);
            if(isCurrSafe) res.push_back(i);
        }
        
        return res;
    }
};