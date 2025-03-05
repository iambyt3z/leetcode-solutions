class Solution {
public:
    long long coloredCells(int n) {
        return (long long) (n-1) * 2 * n + 1;
    }
};