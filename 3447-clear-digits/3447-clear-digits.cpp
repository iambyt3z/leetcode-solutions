class Solution {
public:
    string clearDigits(string s) {
        string res;
        int len = s.length();

        for(int i=0; i<len; i++) {
            if(isdigit(s[i]) && res.size())
                res.pop_back();
            else
                res.push_back(s[i]);
        }

        return res;
    } 
};