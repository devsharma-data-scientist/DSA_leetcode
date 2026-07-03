class Solution {
public:
    vector<string> ans;
    string pick;

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void func(int idx, string &digits) {

        if(idx == digits.size()) {
            ans.push_back(pick);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char ch : letters) {
            pick.push_back(ch);
            func(idx + 1, digits);
            pick.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        func(0, digits);
        return ans;
    }
};