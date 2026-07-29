class KthLargest {
public:
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
    }

    int add(int val) {
        bool inserted = false;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= val) {
                nums.insert(nums.begin() + i, val);
                inserted = true;
                break;
            }
        }

        if(!inserted)
            nums.push_back(val);

        return nums[nums.size() - k];
    }
};