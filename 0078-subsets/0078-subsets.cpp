class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subset = 1<<nums.size();
        vector<vector<int>> sy;
        for(int i=0;i<subset ;i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            sy.push_back(temp);
        }
        return sy;
    }
};