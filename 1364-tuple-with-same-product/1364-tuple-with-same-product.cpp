class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> products;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                products.push_back(nums[i] * nums[j]);

        sort(products.begin(), products.end());
        int lastProd = products[0];
        int count = 1;
        int res = 0;

        for(int i=1; i<products.size(); i++) {
            if(lastProd == products[i]) {
                count++;
                continue;
            }

            if(count == 1) {
                lastProd = products[i];
                count = 1;
                continue;
            }

            int numOfPairs = (count - 1) * count / 2;
            res += 8 * numOfPairs;
            lastProd = products[i];
            count = 1;
        }

        if(count != 1) {
            int numOfPairs = (count - 1) * count / 2;
            res += 8 * numOfPairs;
        }

        return res;
    }
};