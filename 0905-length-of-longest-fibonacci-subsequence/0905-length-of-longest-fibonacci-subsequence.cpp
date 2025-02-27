class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> ind;
        vector<int> dp(n, 1);
        int res = 1;

        for(int i=0; i<n; i++) 
            ind[arr[i]] = i;

        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                int ind1 = i, ind2 = j;
                int len = 2;
                int tar = arr[ind1] + arr[ind2];

                while(tar <= arr[n-1]) {
                    if(ind.count(tar) == 0)
                        break;

                    len++;
                    int indt = ind[tar];
                    ind1 = ind2;
                    ind2 = indt;
                    tar = arr[ind1] + arr[ind2];
                }

                res = max(res, len);
            }
        }

        return (res <= 2) ? 0 : res;
    }
};