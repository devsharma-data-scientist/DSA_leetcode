class Solution {
public:

     vector<int> find_pse(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> pse(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    vector<int> find_nse(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> nse(n);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = find_pse(heights);
        vector<int> nse = find_nse(heights);

        int maxi = 0;

        for(int i = 0; i < heights.size(); i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m,0);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1') v[j]+=1;
                else v[j] = 0;
            }
            maxi = max(maxi , largestRectangleArea(v));
        }
        return maxi;
    }
};