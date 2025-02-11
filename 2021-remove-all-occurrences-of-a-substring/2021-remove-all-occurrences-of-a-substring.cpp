class Solution {
public:
    string removeOccurrences(string s, string part) {
        int lenp = part.length();
        int i=0;

        while(i < s.length()) {
            int ii = i;
            int j = 0;
            int cnt = 0;

            while(ii < s.length() && j < lenp && s[ii] == part[j]) {
                cnt++;
                ii++;
                j++;
            }

            if(cnt == lenp) {
                string tmp = s;
                s = "";

                for(int k=0; k<tmp.length(); k++) {
                    if(k >= i && k < ii)
                        continue;

                    s += tmp[k];
                }

                i = max(i - lenp, 0);
                continue;
            }

            i++;
        }

        return s;
    }
};