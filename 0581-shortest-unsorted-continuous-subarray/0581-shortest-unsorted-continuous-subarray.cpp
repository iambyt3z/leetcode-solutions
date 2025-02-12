class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> sl, sr;
        int l=n-1, r=0;

        for(int i=0; i<n; i++) {
            while(sl.size() && sl.top().first > nums[i]) {
                l = min(l, sl.top().second);
                sl.pop();
            }

            sl.push({ nums[i], i });
        }

        for(int i=n-1; i>=0; i--) {
            while(sr.size() && sr.top().first < nums[i]) {
                r = max(r, sr.top().second);
                sr.pop();
            }

            sr.push({ nums[i], i });
        }

        if(l >= r)
            return 0;

        return (r-l+1);
    }
};