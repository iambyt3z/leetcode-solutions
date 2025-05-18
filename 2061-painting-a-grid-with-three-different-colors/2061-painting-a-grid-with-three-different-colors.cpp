class Solution {
public:
    vector<vector<int>> dp;

    string numToString(int n, int len) {
        string res = "";
        while(len) {
            res += (char) (n%3 + '0');
            n /= 3;
            len--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isValid(string &s) {
        int n = s.length();
        for(int i=1; i<n; i++)
            if(s[i] == s[i-1])
                return false;

        return true;
    }

    bool isValid(string &s1, string &s2) {
        int n = s1.length();
        for(int i=0; i<n; i++)
            if(s1[i] == s2[i])
                return false;
        
        return true;
    }

    vector<string> generate(int len) {
        vector<string> res;
        for(int i=0; i<pow(3, len); i++) {
            string ri = numToString(i, len);
            if(!isValid(ri))
                continue;

            res.push_back(ri);
        }
        return res;
    }

    int solve(int i, int prev_row, int n, vector<string> &valids) {
        if(i == n) return 1;

        if(dp[i][prev_row] != -1)
            return dp[i][prev_row];

        int res = 0;
        for(int ind=0; ind<valids.size(); ind++) {
            string prev_row_bitmask = valids[prev_row];
            string curr_row_bitmask = valids[ind];
            bool valid = isValid(prev_row_bitmask, curr_row_bitmask);

            if(i != 0 && !valid)
                continue;

            res = (res + solve(i+1, ind, n, valids)) % (1000000007);
        }

        return dp[i][prev_row] = res;
    }

    int colorTheGrid(int m, int n) {
        vector<string> valids = generate(m);
        int vn = valids.size();
        dp.assign(n+1, vector<int>(vn+1, -1));
        return solve(0, 0, n, valids);        
    }
};