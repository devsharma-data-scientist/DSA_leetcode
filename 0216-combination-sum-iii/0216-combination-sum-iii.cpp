class Solution {
public:
    vector<vector<int>> ans;
    vector<int> pick;

    void func(int i, int k, int sum) {

        // Base Case
        if(k == 0) {
            if(sum == 0)
                ans.push_back(pick);
            return;
        }

        if(i > 9 || sum < 0)
            return;

        // Pick
        pick.push_back(i);
        func(i + 1, k - 1, sum - i);
        pick.pop_back();

        // Not Pick
        func(i + 1, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        func(1, k, n);
        return ans;
    }
};