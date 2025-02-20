class Solution {
public:
    int binToDec(string s) {
        int n = s.length();
        int mult = 1;
        int res = 0;

        for(int i=n-1; i>=0; i--) {
            res += mult * (s[i] == '1');
            mult *= 2;
        }

        return res;
    }

    string decToBin(int num, int len) {
        string res = "";
        
        while(len) {
            res += (char) (num%2 + '0');
            num /= 2;
            len--;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_map<int, int> vis;
        for(auto num: nums) vis[binToDec(num)]++;

        for(int i=0; i<pow(2, n); i++) {
            if(vis.count(i) != 0)
                continue;

            return decToBin(i, n);
        }

        return "";
    }
};