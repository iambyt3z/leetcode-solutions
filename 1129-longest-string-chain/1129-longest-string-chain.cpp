class Solution {
public:
    bool static cmp(const string &s1, const string &s2) {
        return (s1.size() < s2.size());
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), cmp);
        int n = words.size(), res = 1;

        for(int i=0; i<n; i++) {
            string curr = words[i];
            dp[curr] = 1;
            int len = curr.length();

            for(int i=0; i<len; i++) {
                string prev = "";

                for(int j=0; j<len; j++) {
                    if(i == j) continue;
                    prev += curr[j];
                }

                if(dp.count(prev) != 0)
                    dp[curr] = max(dp[curr], 1 + dp[prev]);
            }

            res = max(res, dp[curr]);
        }

        return res;
    }
};