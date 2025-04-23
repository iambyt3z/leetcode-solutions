class Solution {
public:
    int sumDigits(int n) {
        int res = 0;
        while(n) {
            res += n%10;
            n /= 10;
        }
        return res;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> cnt, cnt2;
        for(int i=1; i<=n; i++) {
            int sum = sumDigits(i);
            cnt[sum]++;
        }

        int maxSize = 0;
        for(auto [k, v]: cnt) {
            maxSize = max(maxSize, v);
            cnt2[v]++;
        }

        return cnt2[maxSize];
    }
};