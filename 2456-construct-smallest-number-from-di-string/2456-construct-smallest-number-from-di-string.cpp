class Solution {
public:
    string res;
    unordered_map<int, int> umap;

    bool check(string &s, string &pat) {
        int n = pat.size();
        for(int i=0; i<n; i++) {
            if(pat[i] == 'I' && s[i] > s[i+1])
                return false;

            if(pat[i] == 'D' && s[i] < s[i+1])
                return false;
        }

        return true;
    }

    bool solve(int i, string &pat) {
        if(i == pat.length()) {
            // cout << res << endl;
            return check(res, pat);
        }

        int prev = (int) (res[i] - '0');
        int dir = (pat[i] == 'I') - (pat[i] == 'D'); 

        for(int curr = prev + dir; (curr<=9 && curr >= 1 ); curr += dir) {
            if(umap.count(curr) == 0)
                continue;

            umap.erase(curr);
            res.push_back((char) (curr + '0'));

            if(solve(i+1, pat)) 
                return true;

            res.pop_back();
            umap[curr]++;
        }

        return false;
    }

    string smallestNumber(string pattern) {
        for(int i=1; i<=9; i++)
            umap[i]++;
        
        for(int curr=1; curr<=9; curr++) {
            res = "";
            res.push_back((char) (curr + '0'));
            umap.erase(curr);

            bool found = solve(0, pattern);
            if(found) return res;

            umap[curr]++;
        }

        return "";
    }
};