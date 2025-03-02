class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> umap;
        int n = nums1.size(), m = nums2.size();

        for(int i=0; i<n; i++) umap[nums1[i][0]] += nums1[i][1];
        for(int i=0; i<m; i++) umap[nums2[i][0]] += nums2[i][1];

        vector<vector<int>> res;
        for(auto [k, v]: umap) res.push_back({ k, v });
        sort(res.begin(), res.end());
        
        return res;
    }
};