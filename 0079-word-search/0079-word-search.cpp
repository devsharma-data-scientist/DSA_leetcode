class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {

        // Pura word match ho gaya
        if (idx == word.size())
            return true;

        // Out of bounds ya character match nahi hua
        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] != word[idx])
            return false;

        // Current character ko visited mark karo
        char temp = board[i][j];
        board[i][j] = '#';

        // 4 directions
        bool found =
            dfs(board, word, i + 1, j, idx + 1) ||
            dfs(board, word, i - 1, j, idx + 1) ||
            dfs(board, word, i, j + 1, idx + 1) ||
            dfs(board, word, i, j - 1, idx + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};