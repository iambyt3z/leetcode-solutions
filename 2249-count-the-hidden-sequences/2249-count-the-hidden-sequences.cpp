class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        pair<int, int> poss = {lower, upper};
        int prefix = 0;

        for(int di: differences) {
            prefix += di;
            pair<int, int> curr = {lower - prefix, upper - prefix};

            if(
                (poss.second >= curr.first && poss.second <= curr.second) || 
                (curr.second >= poss.first && curr.second <= poss.second)
            )
                poss = { max(poss.first, curr.first), min(poss.second, curr.second) };
            else
                return 0;
        }

        return poss.second - poss.first + 1;
    }
};