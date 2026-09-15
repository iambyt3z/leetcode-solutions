class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int res = 0;

        vector<pair<int, int>> signs = {
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };

        for(int dx=0; dx<n; dx++) {
            for(int dy=0; dy<n; dy++) {
                for(int s=0; s<4; s++) {
                    auto [sx, sy] = signs[s];

                    int tempRes = 0;
                    for(int x=0; x<n; x++) {
                        for(int y=0; y<n; y++) {
                            int x1 = x + sx * dx;
                            int y1 = y + sy * dy;
                            int x2 = x;
                            int y2 = y;

                            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n)
                                continue;

                            tempRes += img1[x1][y1] * img2[x2][y2];
                        }
                    }

                    res = max(res, tempRes);
                }
            }
        }

        return res;
    }
};