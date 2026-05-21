class Solution {
public:
    int leftBound(int l, int r, vector<string> &a1, char target, int digit) {
        int res = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(digit >= a1[mid].size()) {
                l = mid+1;
                continue;
            }

            char curr = a1[mid][digit];

            if(curr < target) {
                l = mid+1;
            } else if (curr == target) {
                r = mid-1;
                res = mid;
            } else {
                r = mid-1;
            }
        }

        return res;
    }

    int rightBound(int l, int r, vector<string> &a1, char target, int digit) {
        int res = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(digit >= a1[mid].size()) {
                l = mid+1;
                continue;
            }

            char curr = a1[mid][digit];

            if(curr < target) {
                l = mid+1;
            } else if (curr == target) {
                l = mid+1;
                res = mid;
            } else {
                r = mid-1;
            }
        }

        return res;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> a1, a2;
        for(int num: arr1) a1.push_back(to_string(num));
        for(int num: arr2) a2.push_back(to_string(num));

        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());

        int res = 0;
        for(int i=0; i<a2.size(); i++) {
            string a2i = a2[i];
            int l=0, r=a1.size()-1;
            int ri=0; int digit=0;

            // cout << "a2i = " << a2i << endl; 

            while(digit < a2i.size() && l != -1) {
                // cout << "l = " << l << ", r = " << r << endl;
                // cout << "digit = " << digit << endl; 

                int newL = leftBound(l, r, a1, a2i[digit], digit);
                // cout << "newL = " << newL << endl;

                int newR = rightBound(l, r, a1, a2i[digit], digit);
                // cout << "newR = " << newR << endl;

                ri += (newL != -1);
                l = newL;
                r = newR;
                digit++;
            }

            res = max(res, ri);
        }

        return res;
    }
};