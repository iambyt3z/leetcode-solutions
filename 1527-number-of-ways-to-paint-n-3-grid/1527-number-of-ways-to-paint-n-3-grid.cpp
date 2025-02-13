class Solution {
public:
    long long dp[5000][27];
    int mod = 1000000007;

    string convertToBase3(int num) {
        string res = "";
        while(num) {
            int ch = (char) ( num%3 + '0');
            res.push_back(ch);
            num /= 3;
        }

        while(res.size() < 3)
            res.push_back('0');

        reverse(res.begin(), res.end());

        return res;
    }

    bool isValidState(string curr, string prev = "") {
        bool res1 = true;
        for(int i=0; i<2; i++) 
            res1 = (res1 && curr[i] != curr[i+1]);

        if(prev.size() == 0) return res1;

        bool res2 = true;
        for(int i=0; i<3; i++) 
            res2 = (res2 && curr[i] != prev[i]);
        
        return (res1 && res2);
    }

    long long solve(int i, int prevState, int n) {
        if(i == n)
            return 1;

        if(dp[i][prevState] != -1)
            return dp[i][prevState];

        string prevStateString = convertToBase3(prevState);
        int res = 0;

        for(int currState = 0; currState < 27; currState++) {
            string currStateString = convertToBase3(currState);
            if(!isValidState(currStateString)) continue;
            if(!isValidState(currStateString, prevStateString)) continue;
            res = (res + solve(i+1, currState, n)) % mod;
        }

        return dp[i][prevState] = res;
    }

    int numOfWays(int n) {
        long long res = 0;

        memset(dp, -1, sizeof(dp));
        for(int startState = 0; startState < 27; startState++) {
            string startStateString = convertToBase3(startState);
            if(!isValidState(startStateString)) continue;
            res += solve(1, startState, n);
        }

        return (int) (res % mod);
    }
};