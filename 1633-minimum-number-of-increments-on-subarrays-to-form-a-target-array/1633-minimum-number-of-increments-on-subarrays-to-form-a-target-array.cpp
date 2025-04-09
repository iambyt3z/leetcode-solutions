class Solution {
public:
    int minNumberOperations(vector<int>& s) {
        int n = s.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> leftS, rightS;
        
        for(int i=0; i<n; i++) {
            while(leftS.size() && s[i] <= leftS.top())
                leftS.pop();
                
            if(leftS.size()) left[i] = leftS.top();
            else left[i] = 1;
            
            leftS.push(s[i]);
        }
        
        for(int i=n-1; i>=0; i--) {
            while(rightS.size() && s[i] < rightS.top())
                rightS.pop();
                
            if(rightS.size()) right[i] = rightS.top();
            else right[i] = 1;
            
            rightS.push(s[i]);
        }
        
        long res = 0;
        
        for(int i=0; i<n; i++)
            res += (long) min(s[i] - left[i], s[i] - right[i]);
        
        return res + 1;
    }
};