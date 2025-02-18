class Solution {
public:
    string res;
    vector<bool> available;

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
        if(i == pat.length())
            return check(res, pat);

        int prev = (int) (res[i] - '0');
        int dir = (pat[i] == 'I') - (pat[i] == 'D'); 

        for(
            int curr = prev + dir; 
            curr <= 9 && curr >= 1; 
            curr += dir
        ) {
            if(!available[curr])
                continue;

            available[curr] = false;
            res.push_back((char) (curr + '0'));

            if(solve(i+1, pat)) 
                return true;

            res.pop_back();
            available[curr] = true;
        }

        return false;
    }

    string smallestNumber(string pattern) {
        available.assign(10, true);
        
        for(int curr=1; curr<=9; curr++) {
            res = "";
            res.push_back((char) (curr + '0'));
            available[curr] = false;

            bool found = solve(0, pattern);
            if(found) return res;

            available[curr] = true;
        }

        return "";
    }
};