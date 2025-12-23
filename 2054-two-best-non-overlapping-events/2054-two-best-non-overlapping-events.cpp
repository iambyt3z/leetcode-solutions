class Solution {
public:
    int dp[100001][3];

    int findNext(int last, vector<vector<int>> &events) {
        int res = -1;
        int last_end = events[last][1];
        int l = last+1, r = events.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(events[mid][0] > last_end) {
                res = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
    }

    int solve(int i, int k, int n, vector<vector<int>> &events) {
        if(i == n) return 0;
        if(k == 0) return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        int next_ind = findNext(i, events);
        next_ind = (next_ind == -1) ? n : next_ind;

        return dp[i][k] = max(
            solve(i+1, k, n, events),
            events[i][2] + solve(next_ind, k-1, n, events)
        );
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, 2, n, events);
    }
};