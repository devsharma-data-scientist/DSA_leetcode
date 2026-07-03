class Solution {
public:

    
    vector<vector<int>> ans;

    void func(int ind, vector<int>&nums ,vector<int>&pick){
        if(ind == nums.size()){
            ans.push_back(pick);
            return;
        }

        pick.push_back(nums[ind]);
        func(ind+1,nums,pick);
        pick.pop_back();
        func(ind+1,nums,pick);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> pick;
        func(0,nums,pick);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};