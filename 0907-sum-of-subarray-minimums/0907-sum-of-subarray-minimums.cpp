class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        // Previous Less (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            prevLess[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nextLess[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right) % MOD;
        }

        return ans;
    }
};