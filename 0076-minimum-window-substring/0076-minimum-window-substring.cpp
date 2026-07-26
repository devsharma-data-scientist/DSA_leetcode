class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;

        for (char c : t)
            mpp[c]++;

        int required = t.size();
        int l = 0, r = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {

            if (mpp[s[r]] > 0)
                required--;

            mpp[s[r]]--;
            r++;

            while (required == 0) {

                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                mpp[s[l]]++;

                if (mpp[s[l]] > 0)
                    required++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};