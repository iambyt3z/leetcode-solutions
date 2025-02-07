class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int, int> balls;
        unordered_map<int, unordered_set<int>> colors;
        int n = q.size();
        vector<int> res;

        for(int i=0; i<n; i++) {
            int x = q[i][0], y = q[i][1];

            if(balls.count(x) == 0) {
                balls[x] = y;
                colors[y].insert(x);
                res.push_back(colors.size());
                continue;
            }

            int prev_color = balls[x];
            colors[prev_color].erase(x);
            if(colors[prev_color].size() == 0) colors.erase(prev_color);
            colors[y].insert(x);
            balls[x] = y;
            res.push_back(colors.size());
        }

        return res;
    }
};