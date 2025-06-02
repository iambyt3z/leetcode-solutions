class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cadies(n, 1);

        for(int i=1; i<n; i++)
            if(ratings[i] > ratings[i-1] && cadies[i] <= cadies[i-1])
                cadies[i] = 1 + cadies[i-1];
        
        for(int i=n-2; i>=0; i--)
            if(ratings[i] > ratings[i+1] && cadies[i] <= cadies[i+1])
                cadies[i] = 1 + cadies[i+1];

        return accumulate(cadies.begin(), cadies.end(), 0);
    }
};