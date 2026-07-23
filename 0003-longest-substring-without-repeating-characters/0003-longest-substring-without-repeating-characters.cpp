class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        map<char, int> mpp;
        int maxlen = 0;

        while (r < s.length()) {

            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }

            mpp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};