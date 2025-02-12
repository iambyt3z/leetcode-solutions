class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDist = INT_MAX;
        int n = points.size();
        int res = -1;

        for(int i=0; i<n; i++) {
            int ai = points[i][0], bi = points[i][1];
            int dist = abs(ai - x) + abs(bi - y);

            if((ai == x || bi == y) && dist < minDist) {
                minDist = dist;
                res = i;
            }
        }

        return res;
    }
};