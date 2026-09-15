class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> combs;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                combs.push_back({i, j});
            }
        }

        vector<pair<int, int>> signs = {
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };

        int res = 0;
        for(int c=0; c<combs.size(); c++) {
            auto [dx, dy] = combs[c];

            cout << "d = " << dx << " " << dy << endl;

            for(int s=0; s<4; s++) {
                auto [sx, sy] = signs[s];
                cout << "s = " << sx << " " << sy << endl;

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

                cout << "tempRes = " << tempRes << endl;
                res = max(res, tempRes);
            }
        }

        return res;
    }
};