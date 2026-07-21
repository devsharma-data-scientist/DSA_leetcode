class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char v : num) {

            while (!st.empty() && st.top() > v && k > 0) {
                st.pop();
                k--;
            }

            st.push(v);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};