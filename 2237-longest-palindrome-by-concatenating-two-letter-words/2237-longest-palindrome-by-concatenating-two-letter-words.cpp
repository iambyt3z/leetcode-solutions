class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(auto &s: words) cnt[s]++;

        int res = 0;
        bool tmp = false;

        for(auto [s, v]: cnt) {
            string revs = s;
            reverse(revs.begin(), revs.end());

            while(
                (s == revs && cnt[s] >= 2) ||
                (s != revs && cnt[s] > 0 && cnt.count(revs) && cnt[revs] > 0)
            ) {
                res += 4;
                cnt[s]--;
                cnt[revs]--;
            }

            if(cnt[s] && s[0] == s[1] && !tmp) {
                res += 2;
                tmp = true;
                cnt[s]--;
            }
        }

        return res;
    } 
};