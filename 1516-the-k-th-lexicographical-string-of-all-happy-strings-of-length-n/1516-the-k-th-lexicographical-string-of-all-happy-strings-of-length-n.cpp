class Solution {
public:
    string ri;
    vector<string> res;

    void helper(int i, int n) {
        if(i == n) {
            res.push_back(ri);
            return ;
        }

        int prev = (int) (ri[i-1] - 'a');
        int curr_1 = (prev + 1) % 3;
        int curr_2 = (prev + 2) % 3;

        if(curr_2 > curr_1) {
            ri.push_back((char) (curr_1 + 'a'));
            helper(i+1, n);
            ri.pop_back();

            ri.push_back((char) (curr_2 + 'a'));
            helper(i+1, n);
            ri.pop_back();
        } 
        
        else {
            ri.push_back((char) (curr_2 + 'a'));
            helper(i+1, n);
            ri.pop_back();

            ri.push_back((char) (curr_1 + 'a'));
            helper(i+1, n);
            ri.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        res.clear();

        for(int i=0; i<3; i++) {
            char ch = (char) (i + 'a');
            ri = "";
            ri.push_back(ch);
            helper(1, n);
        }

        if(k > res.size())
            return "";

        return res[k-1];
    }
};