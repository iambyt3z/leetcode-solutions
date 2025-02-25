class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0LL;
        int evenSums = 1, oddSums = 0;
        long long res = 0;

        for(int i=0; i<n; i++) {
            sum += arr[i];
            res += (long long) (sum % 2 == 0) * oddSums + (sum % 2 == 1) * evenSums;
            evenSums += (sum % 2 == 0);
            oddSums += (sum % 2 == 1);
        }

        return (res % 1000000007);
    }
};