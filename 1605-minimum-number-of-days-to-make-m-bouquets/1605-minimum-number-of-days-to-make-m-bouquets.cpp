class Solution {
public:
    bool poss(int m, int k, int max_day, vector<int> &bloomDay) {
        int n = bloomDay.size();
        int tmp = k;

        // cout << "max_day = " << max_day << endl;

        for(int i=0; i<n; i++) {
            if(bloomDay[i] > max_day) {
                tmp = k;
                continue;
            }

            tmp--;

            if(tmp == 0) {
                m--;
                tmp = k;
            }

            // cout << i << " " << m << endl;
        }

        return (m <= 0);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(poss(m, k, mid, bloomDay)) {
                r = mid-1;
                res = mid;
            } else {
                l = mid+1;
            }
        }

        return res;
    }
};