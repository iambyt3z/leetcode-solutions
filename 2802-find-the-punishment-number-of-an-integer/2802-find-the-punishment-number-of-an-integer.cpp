class Solution {
public:
    bool isValid(string s, int num) {
        int len = s.length();

        for(int state = 0; state < pow(2, len); state++) {
            string tmp = "";
            int tmp_num = 0;

            for(int i=0; i<len; i++) {
                tmp.push_back(s[i]);
                int leftShifts = (len-1-i);
                int bitmask = (1 << leftShifts);

                if(state & bitmask) {
                    tmp_num += stoi(tmp);
                    tmp = "";
                }
            }

            if(tmp.length())
                tmp_num += stoi(tmp);

            if(tmp_num == num)
                return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for(int i=1; i<=n; i++) res += (i*i) * isValid(to_string(i*i), i);
        return res;
    }
};