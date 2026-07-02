class Solution {
private:
    void findCombinations(int ind, vector<int>& arr, int target,
                          vector<vector<int>>& ans, vector<int>& ds) {

        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick the current element
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinations(ind, arr, target - arr[ind], ans, ds);
            ds.pop_back();
        }

        // Don't pick the current element
        findCombinations(ind + 1, arr, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0, candidates, target, ans, ds);

        return ans;
    }
};