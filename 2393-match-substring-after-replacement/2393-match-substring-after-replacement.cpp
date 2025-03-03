class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_map<char, int>> map;
        for(int i=0; i<mappings.size(); i++) {
            char old = mappings[i][0];
            char next = mappings[i][1];
            map[old][next]++;
        }
        
        int n = s.length(), m = sub.length();

        for(int i=0; i<=n-m; i++) {
            string curr = s.substr(i, m);
            int cnt = 0;

            for(int j=0; j<m; j++) {
                if(sub[j] == curr[j]) {
                    cnt++;
                    continue;
                }

                else if( map[ sub[j] ][ curr[j] ] ) {
                    cnt++;
                    continue;
                }

                else
                    break;
            }

            if(cnt == m)
                return true;
        }

        return false;
    }
};