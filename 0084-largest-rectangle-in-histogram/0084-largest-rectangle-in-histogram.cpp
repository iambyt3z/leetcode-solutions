class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> s;

        int res = 0;
        for(int i=0; i<n; i++) {
            int hi = heights[i];

            if(s.empty() || hi >= s.top().first) {
                s.push({ hi, i });
                continue;
            }

            int ind = i;
            while(!s.empty() && hi < s.top().first) {
                auto [hs, is] = s.top();
                s.pop();
                res = max(res, (i - is) * hs);
                ind = is;
            }

            s.push({ hi, ind });
        }

        while(!s.empty()) {
            auto [hs, is] = s.top();
            s.pop();
            res = max(res, (n - is) * hs);
        }

        return res;
    }
};