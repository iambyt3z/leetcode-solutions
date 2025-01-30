class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1);
        stack<int> s;

        for(int i=n-1; i>=0; i--) {
            auto car = cars[i];
            int pos = car[0], speed = car[1];

            while(s.size() && speed <= cars[s.top()][1])
                s.pop();

            double collTime = -1;
            while(s.size()) {
                collTime = (double) (cars[s.top()][0] - pos) / (speed - cars[s.top()][1]);
                if(collTime <= res[s.top()] || res[s.top()] == -1) break;
                else s.pop();
            }

            res[i] = collTime;
            s.push(i);
        }

        return res;
    }
};