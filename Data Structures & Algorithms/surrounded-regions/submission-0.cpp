class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        
        // Helper DFS to mark safe 'O's as 'T'
        // We use a lambda so we don't have to pass 'board', 'm', 'n' every time
        function<void(int, int)> dfs = [&](int r, int c) {
            // Out of bounds or not an 'O'? Stop.
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
            
            board[r][c] = 'T'; // Mark as safe
            
            // Spread to 4 directions
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };
        
        // 1. Seed DFS from top and bottom borders
        for (int c = 0; c < n; c++) {
            dfs(0, c);         // Top row
            dfs(m - 1, c);     // Bottom row
        }
        
        // 2. Seed DFS from left and right borders
        for (int r = 0; r < m; r++) {
            dfs(r, 0);         // Left col
            dfs(r, n - 1);     // Right col
        }
        
        // 3. Final sweep: convert 'T' -> 'O' (safe) and 'O' -> 'X' (trapped)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Trapped, flip it
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // Safe, restore it
                }
            }
        }
    }
};