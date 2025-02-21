class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> prefixSum;
        unordered_map<int, int> ind;
        int sum = 0, res = 0, n = hours.size();

        for(int i=0; i<n; i++) {
            int h = hours[i];
            sum += (h > 8) - (h <= 8);
            if(ind.count(sum) == 0) ind[sum] = i;

            if(sum > 0) res = max(res, i+1);
            else if(ind.count(sum-1)) res = max(res, i-ind[sum-1]);
        }

        return res;
    }
};