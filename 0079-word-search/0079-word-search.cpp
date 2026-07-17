class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis,
             string& word, int i, int j, int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (vis[i][j] || board[i][j] != word[idx])
            return false;

        vis[i][j] = true;

        bool found =
            dfs(board, vis, word, i + 1, j, idx + 1) ||
            dfs(board, vis, word, i - 1, j, idx + 1) ||
            dfs(board, vis, word, i, j + 1, idx + 1) ||
            dfs(board, vis, word, i, j - 1, idx + 1);
        
        vis[i][j] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, vis, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};