class Solution {
public:
    int calcHamming(string &s1, string &s2) {
        int res = 0;
        for(int i=0; i<s1.length(); i++)
            res += (s1[i] != s2[i]);

        return res;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> choice(n, -1);

        int maxInd = 0, resLen = 1;
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(groups[i] == groups[j]) continue;
                if(words[i].size() != words[j].size()) continue;
                if(calcHamming(words[i], words[j]) != 1) continue;

                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    choice[i] = j;
                }
            }
            
            if(dp[i] > resLen) {
                resLen = dp[i];
                maxInd = i;
            }
        }

        vector<string> res;
        int i = maxInd;
        while(i >= 0) {
            res.push_back(words[i]);
            i = choice[i];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};