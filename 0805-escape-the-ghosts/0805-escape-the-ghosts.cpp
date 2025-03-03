class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int t = abs(target[0]) + abs(target[1]);
        int n = ghosts.size();

        for(int i=0; i<n; i++) {
            int x = ghosts[i][0], y = ghosts[i][1];
            int ti = abs(x - target[0]) + abs(y - target[1]);
            if(t >= ti) return false;
        }

        return true;
    }
};