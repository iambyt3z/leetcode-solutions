class Solution {
public:
    int fact(int n) {
        if(n == 0)
            return 1;
        return n * fact(n-1);
    }

    int helper(string &s) {
        vector<int> cnt(26, 0);
        int len = s.length();
        int res = fact(len);

        for(char ch: s) {
            int ind = (int) (ch - 'A');
            cnt[ind]++;
        }

        for(int i=0; i<26; i++)
            res /= fact(cnt[i]);

        return res;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<string, int> umap;
        int n = tiles.length();
        int res = 0;

        for(int state=0; state<pow(2, n); state++) {
            string tmp = "";

            for(int i=0; i<n; i++) {
                int leftShift = n-1-i;
                int bitmask = (1 << leftShift);
                if(state & bitmask) tmp.push_back(tiles[i]);
            }

            sort(tmp.begin(), tmp.end());
            if(tmp.length() == 0 || umap.count(tmp) != 0) continue;

            int ri = helper(tmp);
            umap[tmp] = ri;
            res += ri;
        }

        return res;
    }
};