class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int res = 0;
        int l=0, r=0;
        unordered_map<int, int> cnt;
        cnt[fruits[0]]++;

        while(true) {
            if(cnt.size() <= 2) {
                res = max(r-l+1, res);
                r++;

                if(r == n) break;
                cnt[fruits[r]]++;
            }

            else {
                cnt[fruits[l]]--;
                if(cnt[fruits[l]] == 0)
                    cnt.erase(fruits[l]);
                l++;
            }
        }

        return res;
    }
};