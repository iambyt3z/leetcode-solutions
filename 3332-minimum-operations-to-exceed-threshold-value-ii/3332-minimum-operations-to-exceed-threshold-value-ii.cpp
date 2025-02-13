class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int &ni: nums) pq.push((long long) ni);

        int res = 0;
        while(pq.size() >= 2 && pq.top() < (long long) k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push( min(x, y) * 2 + max(x, y) );
            res++;
        }

        return res;
    }
};