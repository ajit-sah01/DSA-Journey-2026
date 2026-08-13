// class Solution {
// public:

//     bool isSafe(vector<string> &board, int row, int col , int n){ // O(n) 
//         ////Horiziontal
//         for(int j =0; j<n; j++){
//             if(board[row][j] == 'Q'){
//                 return false;
//             }
//         }

//         // Vertical
//         for(int i =0; i<n; i++){
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//         }

//         // Left Diogonal
//         for(int i = row , j=col; i>=0 && j>=0 ; i--, j--){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }

//         // Right Diogonal
//         for(int i = row , j=col; i>=0 && j>=0 ; i--, j++){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }

//         return true;
//     }


//     void nQueens(vector<string> &board, int row, int n , vector<vector<string>> &ans ){

//         if(row == n){
//             ans.push_back({board});
//             return;
//         }


//         for(int j =0; j<n ; j++){
//             if(isSafe(board, row, j ,n)){
//                 board[row][j] = 'Q';
//                 nQueens(board, row+1,n,ans);
//                 board[row][j] = '.';
//             }
//         }
//     }
    

//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n , string(n, '.'));
//         vector<vector <string>> ans;

//         nQueens(board, 0,  n , ans );
//         return ans;
//     }
// };




class Solution {
public:
    vector<vector<string>> ans;
    vector<int> col, diag1, diag2;

    void solve(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (col[j] || diag1[row - j + n - 1] || diag2[row + j])
                continue;

            board[row][j] = 'Q';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = 1;

            solve(row + 1, n, board);

            board[row][j] = '.';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        solve(0, n, board);
        return ans;
    }
};