class Solution {
public:
    int helper(int n) {
        return (n * (n+1)) / 2;
    }

    int differenceOfSums(int n, int m) {
        return helper(n) - 2 * helper(n/m) * m;
    }
};