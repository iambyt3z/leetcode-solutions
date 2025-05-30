class Solution {
public:
    pair<int, int> helper(vector<int> &edges, int node1, int node2) {
        unordered_map<int, int> vis1, vis2;
        
        int curr = node1;
        int dist = 0;
        while(curr != -1 && vis1.count(curr) == 0) {
            vis1[curr] = dist;
            curr = edges[curr];
            dist++;
        }

        curr = node2;
        while(curr != -1 && vis2.count(curr) == 0) {
            if(vis1.count(curr) != 0)
                return {vis1[curr], curr};
            
            vis2[curr]++;
            curr = edges[curr];
            dist++;
        }

        return {-1, -1};
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto [d1, r1] = helper(edges, node1, node2);
        auto [d2, r2] = helper(edges, node2, node1);

        cout << d1 << " " << r1 << endl;
        cout << d2 << " " << r2 << endl;
        
        if(d1 == -1) return -1;
        else if(d1 < d2) return r1;
        else if(d1 == d2) return ((r1 < r2) ? r1 : r2);
        else return r2;
    }
};