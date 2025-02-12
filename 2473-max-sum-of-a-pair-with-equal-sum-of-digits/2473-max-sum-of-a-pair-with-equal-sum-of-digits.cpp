class Solution {
public:
    int sumOfDigits(int n) {
        int res = 0;
        
        while(n) {
            res += (n%10);
            n /= 10;
        }

        return res;
    }

    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> v;

        for(int i=0; i<nums.size(); i++) {
            v.push_back({
                sumOfDigits(nums[i]), 
                nums[i]
            });
        }

        int res = -1;
        sort(v.begin(), v.end());

        for(int i=1; i<v.size(); i++) {
            int sc = v[i].first, nc = v[i].second;
            int sp = v[i-1].first, np = v[i-1].second;

            if(sc == sp)
                res = max(res, nc+np);
        }

        return res;
    }
};