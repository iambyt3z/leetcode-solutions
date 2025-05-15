class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res1, res2;
        int n = words.size();
        int curr = 0;

        for(int i=0; i<n; i++) {
            if(groups[i] == curr) {
                res1.push_back(words[i]);
                curr = 1 - curr;
                continue;
            }
        }

        curr = 1;
        for(int i=0; i<n; i++) {
            if(groups[i] == curr) {
                res2.push_back(words[i]);
                curr = 1 - curr;
                continue;
            }
        }

        if(res1.size() > res2.size())
            return res1;

        return res2;
    }
};