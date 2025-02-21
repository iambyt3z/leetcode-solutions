class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n, -1LL);
        unordered_map<int, vector<int>> ind;

        for(int i=0; i<n; i++)
            ind[arr[i]].push_back(i);

        for(auto &[ai, indi]: ind) {
            int len = indi.size();
            vector<long long> leftPrefix(len, 0);
            long long sum = 0LL;

            for(int i=0; i<len; i++) {
                sum += indi[i];
                leftPrefix[i] = sum;
            }

            for(int i=0; i<len; i++) {
                int index = indi[i];
                long long leftSum = leftPrefix[i];
                res[index] = (sum - 2 * leftSum) + (long long) (2*i + 2 - len) * index;
            }
        }

        return res;
    }
};