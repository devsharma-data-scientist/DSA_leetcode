class Solution {
public:

    string solve(string s, int n) {
        if(n == 1)
            return s;

        string ans = "";
        int i = 0;

        while(i < s.size()) {
            int count = 0;
            char ch = s[i];

            while(i < s.size() && s[i] == ch) {
                count++;
                i++;
            }

            ans += to_string(count);
            ans += ch;
        }

        return solve(ans, n - 1);
    }

    string countAndSay(int n) {
        return solve("1", n);
    }
};