class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(top+1);
        sort(special.begin(), special.end());
        int n = special.size();

        int prev = bottom-1;
        int res = 0;
        for(int i=0; i<n; i++) {
            res = max(res, special[i] - prev - 1);
            prev = special[i];
        }

        return res;
    }
};