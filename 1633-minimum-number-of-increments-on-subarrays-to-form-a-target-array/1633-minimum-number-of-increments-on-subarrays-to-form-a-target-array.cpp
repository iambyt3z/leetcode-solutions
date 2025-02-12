class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        stack<int> sl, sr;
        vector<int> left(n, -1), right(n, -1);

        for(int i=0; i<n; i++) {
            while(sl.size() && sl.top() >= target[i]) sl.pop();
            if(sl.size()) left[i] = sl.top();
            else left[i] = 1;
            sl.push(target[i]);
        }

        for(int i=n-1; i>=0; i--) {
            while(sr.size() && sr.top() > target[i]) sr.pop();
            if(sr.size()) right[i] = sr.top();
            else right[i] = 1;
            sr.push(target[i]);
        }

        int res = 0;

        for(int i=0; i<n; i++)
            res += min(target[i] - left[i], target[i] - right[i]);

        return res+1;
    }
};