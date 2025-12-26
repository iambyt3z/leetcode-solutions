class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> penRight(n+2, 0), penLeft(n+1, 0);

        int total = 0;
        for(int i=0; i<n; i++) {
            total += (customers[i] == 'N');
            penLeft[i] = total;
        }

        total = 0;
        for(int i=n-1; i>=0; i--) {
            total += (customers[i] == 'Y');
            penRight[i] = total;
        }

        int minPen = INT_MAX, res = -1;
        for(int i=0; i<=n; i++) {
            int currPen;

            if(i == 0)
                currPen = 0 + penRight[i];
            else
                currPen = penLeft[i-1] + penRight[i];

            if(currPen < minPen) {
                minPen = currPen;
                res = i;
            } 
        }

        return res;
    }
};