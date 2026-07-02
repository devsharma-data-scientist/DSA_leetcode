class Solution {
private:
    void solve(int ind, vector<int>& arr, int target,
               vector<int>& ds, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);
            solve(i + 1, arr, target - arr[i], ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};