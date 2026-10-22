class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int duplicate = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                double slope;

                if (dx == 0)
                    slope = 1e9;
                else
                    slope = (double)dy / dx;

                mp[slope]++;
                currMax = max(currMax, mp[slope]);
            }

            ans = max(ans, currMax + duplicate + 1);
        }

        return ans;
    }
};